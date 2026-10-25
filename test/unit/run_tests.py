#!/usr/bin/env python3
"""One independent C fixture per test, with PASS/FAIL like Robcmp's general suite."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parent


def run(command, timeout=10):
    result = subprocess.run(
        command,
        capture_output=True,
        timeout=timeout
    )

    result.stdout = result.stdout.decode("utf-8")

    result.stderr = result.stderr.decode(
        "utf-8",
        errors="backslashreplace"
    )

    return result
def require(result, command):
    if result.returncode:
        raise AssertionError(f"{command}: exit {result.returncode}\n{result.stderr}")


def executable(value):
    if not value:
        return None
    found = shutil.which(value)
    return found or (str(Path(value).resolve()) if Path(value).is_file() else None)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--c2rob', default='../../c2rob')
    parser.add_argument('--out', default='out')
    parser.add_argument('--robcmp')
    parser.add_argument('--opt', default='opt')
    parser.add_argument('--cc', default='cc')
    parser.add_argument('--objcopy', default='objcopy')
    parser.add_argument('--arch', default='stm32f1')
    parser.add_argument('--filter', default='')
    args = parser.parse_args()
    translator = executable(args.c2rob)
    if not translator:
        parser.error('C2rob executable not found')
    out = Path(args.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    compiler = executable(args.robcmp)
    verifier = executable(args.opt)
    cc = executable(args.cc)
    objcopy = executable(args.objcopy)
    if args.robcmp is not None and not compiler:
        parser.error('Integration requires an existing --robcmp executable')
    results = []
    for name, spec in json.loads((ROOT / 'cases.json').read_text()).items():
        if args.filter and args.filter not in name:
            continue
        row = {'name': name, 'translation': 'pending', 'object': 'pending',
               'ir': 'pending', 'execution': 'pending'}
        source = ROOT / f'{name}.c'
        rob = out / f'{name}.rob'
        try:
            translator_options = ["--abi=" + spec["abi"]] if "abi" in spec else []
            translated = run([translator, *translator_options, str(source)])
            (out / f'{name}.stderr').write_text(translated.stderr)
            rob.write_text(translated.stdout)
            row['exit'] = translated.returncode
            if 'diagnostic' in spec:
                assert translated.returncode > 0, 'Unsupported input must fail without a signal'
                assert spec['diagnostic'] in translated.stderr, translated.stderr
                assert not translated.stdout.strip(), 'Failure must not emit apparently valid ROB'
                row.update(translation='pass', object='not_applicable', ir='not_applicable', execution='not_applicable')
                print(f'[PASS] {name}: expected diagnostic')
                results.append(row)
                continue
            require(translated, 'C -> ROB')
            for fragment in spec.get('contains', []):
                assert fragment in translated.stdout, f'Missing {fragment!r}\n{translated.stdout}'
            golden = ROOT / f'{name}.expected.rob'
            if golden.exists():
                assert translated.stdout == golden.read_text(), 'Golden ROB regression differs'
            row['translation'] = 'pass'
            print(f'[PASS] {name}: C -> ROB')
            if not args.robcmp:
                row.update(object='skipped', ir='skipped', execution='skipped')
            else:
                # Supply an entry point only for fixtures without main.
                validation_rob = out / f'{name}.validation.rob'
                has_main = spec.get('has_main', False)
                adapter = '' if has_main else '\nint32 main() { return 0; }\n'

                validation_rob.write_text(translated.stdout + adapter)

                row['validation_adapter'] = (
                    'none; fixture already defines main'
                    if has_main else
                    'main entry point added to a separate .validation.rob'
                )
                obj = out / f'{name}.arm.o'
                obj.unlink(missing_ok=True)
                row['object'] = 'fail'
                require(run([compiler, '-O0', '-a', args.arch, '-o', str(obj), str(validation_rob)]), 'ROB -> ARM object')
                assert obj.is_file() and obj.stat().st_size, 'Missing ARM object'
                row['object'] = 'pass'
                row['ir'] = 'fail'
                ir = run([compiler, '-O0', '-a', args.arch, str(validation_rob)])
                require(ir, 'ROB -> LLVM IR')
                ll = out / f'{name}.ll'
                ll.write_text(ir.stdout)
                if verifier:
                    require(run([verifier, '-passes=verify', '-disable-output', str(ll)]), 'LLVM verify')
                    row['ir'] = 'pass'
                else:
                    row['ir'] = 'skipped_missing_opt'
                calls = spec.get(
                    'calls',
                    [[n] for n in spec.get('inputs', [])]
                )

                if cc and (has_main or (objcopy and calls)):
                    row['execution'] = 'fail'

                    host = out / f'{name}.host.o'
                    host.unlink(missing_ok=True)

                    require(
                        run([
                            compiler, '-O0', '-o',
                            str(host), str(validation_rob)
                        ]),
                        'ROB -> host object'
                    )

                    original_exe = out / f'{name}.c.exe'
                    rob_exe = out / f'{name}.rob.exe'

                    if has_main:
                        require(
                            run([
                                cc, '-std=c11', '-O0',
                                str(source), '-o', str(original_exe)
                            ]),
                            'Build original C program'
                        )

                        require(
                            run([
                                cc, '-no-pie',
                                str(host), '-o', str(rob_exe)
                            ]),
                            'Link ROB program'
                        )

                    else:
                        require(
                            run([
                                objcopy, '--redefine-sym',
                                'main=rob_validation_main', str(host)
                            ]),
                            'Rename adapter entry point in host object'
                        )

                        entry = spec.get('entry', 'teste')
                        arity = len(calls[0])

                        assert all(
                            len(call) == arity for call in calls
                        ), 'Inconsistent test call arity'

                        parameters = ', '.join(['int'] * arity) or 'void'

                        statements = ''.join(
                            f'printf("%d\\n", {entry}({", ".join(map(str, call))}));\n'
                            for call in calls
                        )

                        harness = out / f'{name}.driver.c'
                        harness.write_text(
                            '#include <stdio.h>\n'
                            '#ifdef ROB_VALIDATION\n'
                            'extern int rob_validation_main(void);\n'
                            '#endif\n'
                            + f'extern int {entry}({parameters});\n'
                            + 'int main(void) {\n'
                            + '#ifdef ROB_VALIDATION\n'
                            + 'rob_validation_main();\n'
                            + '#endif\n'
                            + statements
                            + 'return 0;\n}\n'
                        )

                        require(
                            run([
                                cc, '-std=c11', '-O0',
                                str(source), str(harness),
                                '-o', str(original_exe)
                            ]),
                            'Build original C'
                        )

                        require(
                            run([
                                cc, '-DROB_VALIDATION', '-no-pie',
                                str(host), str(harness),
                                '-o', str(rob_exe)
                            ]),
                            'Link ROB host object'
                        )

                    original = run([str(original_exe)])
                    emitted = run([str(rob_exe)])

                    expected_exit = spec.get('exit_code', 0)

                    assert original.returncode == expected_exit, (
                        f'C exit {original.returncode} != {expected_exit}'
                    )

                    assert emitted.returncode == expected_exit, (
                        f'ROB exit {emitted.returncode} != {expected_exit}'
                    )

                    assert original.stdout == emitted.stdout, (
                        f'C {original.stdout!r} != ROB {emitted.stdout!r}'
                    )

                    if 'expected' in spec:
                        expected = ''.join(
                            f'{value}\n' for value in spec['expected']
                        )

                        assert emitted.stdout == expected, (
                            f'ROB {emitted.stdout!r} != expected {expected!r}'
                        )

                    row['execution'] = 'pass'
                    row['values'] = emitted.stdout.splitlines()
                    row['c_values'] = original.stdout.splitlines()
                    row['exit_code'] = emitted.returncode

                else:
                    row['execution'] = (
                        'skipped_no_calls'
                        if not has_main and not calls else
                        'skipped_missing_cc_or_objcopy'
                    )
                print(f'[PASS] {name}: ARM object / IR {row["ir"]} / execution {row["execution"]}')
        except (AssertionError, subprocess.TimeoutExpired, OSError) as exc:
            if row['translation'] == 'pending':
                row['translation'] = 'fail'
            row['failure'] = str(exc)
            for stage in ['object', 'ir', 'execution']:
                if row[stage] == 'pending':
                    row[stage] = 'not_attempted'
            print(f'[FAIL] {name}: {exc}')
        results.append(row)
    (out / 'results.json').write_text(json.dumps(results, indent=2, ensure_ascii=False) + '\n')
    failed = sum('failure' in row for row in results)
    print(f'{len(results) - failed} passed, {failed} failed; detailed results: {out / "results.json"}')
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())
