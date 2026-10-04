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
    return subprocess.run(command, capture_output=True, text=True, timeout=timeout)


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
            translated = run([translator, str(source)])
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
                # Current Robcmp dereferences a missing main in Program::generate.
                # Keep the exact translation in .rob; add an entry point only in this adapter.
                validation_rob = out / f'{name}.validation.rob'
                validation_rob.write_text(translated.stdout + '\nint32 main() { return 0; }\n')
                row['validation_adapter'] = 'main entry point added to a separate .validation.rob'
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
                if cc and objcopy and spec.get('inputs'):
                    row['execution'] = 'fail'
                    host = out / f'{name}.host.o'
                    host.unlink(missing_ok=True)
                    require(run([compiler, '-O0', '-o', str(host), str(validation_rob)]), 'ROB -> host object')
                    require(run([objcopy, '--redefine-sym', 'main=rob_validation_main', str(host)]), 'Rename adapter entry point in host object')
                    entry = spec.get('entry', 'teste')
                    calls = ''.join(f'printf("%d\\n", {entry}({n}));\n' for n in spec['inputs'])
                    harness = out / f'{name}.driver.c'
                    harness.write_text('#include <stdio.h>\n#ifdef ROB_VALIDATION\nextern int rob_validation_main(void);\n#endif\n'
                                       + f'extern int {entry}(int);\nint main(void) {{\n'
                                       + '#ifdef ROB_VALIDATION\nrob_validation_main();\n#endif\n'
                                       + calls + 'return 0;\n}\n')
                    original_exe = out / f'{name}.c.exe'
                    rob_exe = out / f'{name}.rob.exe'
                    require(run([cc, '-std=c11', '-O0', str(source), str(harness), '-o', str(original_exe)]), 'Build original C')
                    require(run([cc, '-DROB_VALIDATION', '-no-pie', str(host), str(harness), '-o', str(rob_exe)]), 'Link ROB host object')
                    original = run([str(original_exe)])
                    emitted = run([str(rob_exe)])
                    require(original, 'Run C')
                    require(emitted, 'Run ROB')
                    assert original.stdout == emitted.stdout, f'C {original.stdout!r} != ROB {emitted.stdout!r}'
                    row['execution'] = 'pass'
                    row['values'] = emitted.stdout.splitlines()
                    row['c_values'] = original.stdout.splitlines()
                else:
                    row['execution'] = 'skipped_missing_cc_or_objcopy_or_inputs'
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
