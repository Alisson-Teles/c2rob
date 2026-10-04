#!/usr/bin/env python3
"""Measure C->ROB and ROB->object separately on identical, unmodified input files."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import subprocess


def invoke(command, stdout_path, stderr_path):
    try:
        result = subprocess.run(command, capture_output=True, timeout=10)
        status, stdout, stderr = result.returncode, result.stdout, result.stderr
    except subprocess.TimeoutExpired as error:
        status, stdout, stderr = 'timeout', error.stdout or b'', error.stderr or b''
    stdout_path.write_bytes(stdout)
    stderr_path.write_bytes(stderr)
    return status


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--before', required=True)
    parser.add_argument('--after', required=True)
    parser.add_argument('--sample', required=True)
    parser.add_argument('--out', default='out-sample')
    parser.add_argument('--robcmp')
    parser.add_argument('--opt')
    parser.add_argument('--arch', default='stm32f1')
    args = parser.parse_args()
    sample = Path(args.sample).resolve()
    out = Path(args.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    rows = []
    for index, source in enumerate(sorted(sample.rglob('*.c'))):
        row = {'index': f'{index:04d}', 'file': str(source.relative_to(sample)),
               'sha256_c': hashlib.sha256(source.read_bytes()).hexdigest()}
        for phase, translator in [('before', args.before), ('after', args.after)]:
            directory = out / phase
            directory.mkdir(exist_ok=True)
            stem = directory / row['index']
            rob = stem.with_suffix('.rob')
            status = invoke([str(Path(translator).resolve()), str(source)], rob, stem.with_suffix('.translation.stderr'))
            row[f'{phase}_translation_exit'] = status
            row[f'{phase}_rob_bytes'] = rob.stat().st_size
            row[f'{phase}_object_exit'] = 'not_attempted'
            row[f'{phase}_ir_exit'] = 'not_attempted'
            if status == 0 and row[f'{phase}_rob_bytes'] and args.robcmp:
                obj = stem.with_suffix('.o')
                obj.unlink(missing_ok=True)
                object_status = invoke([args.robcmp, '-O0', '-a', args.arch, '-o', str(obj), str(rob)],
                                       stem.with_suffix('.object.stdout'), stem.with_suffix('.object.stderr'))
                row[f'{phase}_object_exit'] = object_status
                row[f'{phase}_object_bytes'] = obj.stat().st_size if obj.exists() else 0
                # IR is checked independently, even when object generation fails.
                ll = stem.with_suffix('.ll')
                ir_status = invoke([args.robcmp, '-O0', '-a', args.arch, str(rob)], ll, stem.with_suffix('.ir.stderr'))
                row[f'{phase}_ir_exit'] = ir_status
                if ir_status == 0 and args.opt:
                    row[f'{phase}_verify_exit'] = invoke([args.opt, '-passes=verify', '-disable-output', str(ll)],
                                                        stem.with_suffix('.verify.stdout'), stem.with_suffix('.verify.stderr'))
        rows.append(row)
    fields = list(dict.fromkeys(key for row in rows for key in row))
    with (out / 'comparison.csv').open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)
    summary = {'files': len(rows), 'preprocessing': 'none; original .c files', 'arch': args.arch}
    for phase in ['before', 'after']:
        summary[phase] = {
            'translation_success': sum(r[f'{phase}_translation_exit'] == 0 and r[f'{phase}_rob_bytes'] > 0 for r in rows),
            'object_success': sum(r[f'{phase}_object_exit'] == 0 and r.get(f'{phase}_object_bytes', 0) > 0 for r in rows),
            'ir_success': sum(r[f'{phase}_ir_exit'] == 0 for r in rows),
            'verified_ir_success': sum(r.get(f'{phase}_verify_exit') == 0 for r in rows),
        }
    summary['new_translation_successes'] = [r['file'] for r in rows if r['before_translation_exit'] != 0 and r['after_translation_exit'] == 0]
    summary['lost_translation_successes'] = [r['file'] for r in rows if r['before_translation_exit'] == 0 and r['after_translation_exit'] != 0]
    (out / 'summary.json').write_text(json.dumps(summary, indent=2, ensure_ascii=False) + '\n')
    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == '__main__':
    main()
