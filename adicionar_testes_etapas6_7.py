#!/usr/bin/env python3
"""Add the official tests for C2ROB stage 6 or stage 7.

Run from the C2ROB root. --check previews changes without writing.
Existing tests with different contents cause an error before any files change.
The compiler sources are never modified. No external packages are required.
"""
import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import sys

TESTS = json.loads(r'''
{
  "return_void_while": {
    "stage": 6,
    "source": "int estado = 0;\nvoid limitar(int n) {\n    while (n > 0) {\n        estado++;\n        if (estado == 2) return;\n        n--;\n    }\n}\nint teste(int n) { estado = 0; limitar(n); return estado; }\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        0,
        1,
        2
      ]
    }
  },
  "return_nonvoid": {
    "stage": 6,
    "source": "int teste(int n) { return; }\n",
    "case": {
      "diagnostic": "return; is only allowed in a void function"
    }
  },
  "return_void_value": {
    "stage": 6,
    "source": "void iniciar(void) { return 1; }\n",
    "case": {
      "diagnostic": "a void function cannot return an expression"
    }
  },
  "multi_local_init": {
    "stage": 7,
    "source": "int teste(int n) {\n    int a = n, b = a + 2, c = b + 3;\n    while (a > 0) { a--; }\n    return a + b + c;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        1,
        7,
        17
      ]
    }
  },
  "multi_local_mixed": {
    "stage": 7,
    "source": "int teste(int n) {\n    int a, b = n, c;\n    a = 2;\n    c = b + a;\n    return c;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        0,
        2,
        7
      ]
    }
  },
  "multi_calls_once": {
    "stage": 7,
    "source": "int chamadas = 0;\nint proximo(void) { chamadas++; return chamadas; }\nint teste(int n) {\n    chamadas = 0;\n    int a = proximo(), b = proximo(), c = proximo();\n    return a * 100 + b * 10 + c + chamadas;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        126,
        126,
        126
      ]
    }
  },
  "multi_global_plain": {
    "stage": 7,
    "source": "int a, b;\nint teste(int n) {\n    a = n;\n    b = 4;\n    return a + b;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        2,
        4,
        9
      ]
    }
  },
  "multi_arrays_init": {
    "stage": 7,
    "source": "int teste(int n) {\n    int a[2] = {1, 2}, b[2] = {3, 4};\n    return a[0] + a[1] + b[0] + b[1] + n;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        8,
        10,
        15
      ],
      "contains": [
        "a = {int32(1), 2};",
        "b = {int32(3), 4};"
      ]
    }
  },
  "multi_array_mixed": {
    "stage": 7,
    "source": "int teste(int n) {\n    int valor = n, itens[2] = {2, 3}, resto;\n    resto = itens[0] + itens[1];\n    return valor + resto;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        3,
        5,
        10
      ]
    }
  },
  "multi_arrays_plain": {
    "stage": 7,
    "source": "int teste(int n) {\n    int a[2], b[2];\n    a[0] = n;\n    b[1] = 3;\n    return a[0] + b[1];\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        1,
        3,
        8
      ]
    }
  },
  "multi_arrays_while": {
    "stage": 7,
    "source": "int teste(int n) {\n    int soma = 0;\n    while (n > 0) {\n        int valores[2] = {n, n + 1}, t = valores[0];\n        soma += t + valores[1];\n        n--;\n    }\n    return soma;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        3
      ],
      "expected": [
        0,
        3,
        15
      ]
    }
  },
  "multi_typedef": {
    "stage": 7,
    "source": "typedef int Numero;\nNumero a = 1, b = 2;\nint teste(int n) {\n    Numero x = n, y = x + a;\n    while (y > 0) { y--; }\n    return x + b;\n}\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        0,
        2,
        7
      ]
    }
  },
  "multi_for_body": {
    "stage": 7,
    "source": "int teste(int n) {\n    int i = 0, total = 0;\n    for (i = 0; i < n; i++) {\n        int a = i, b = a + 1;\n        total += a + b;\n    }\n    return total;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        4
      ],
      "expected": [
        0,
        1,
        16
      ]
    }
  },
  "multi_global_static": {
    "stage": 7,
    "source": "static int a = 1, b = 2;\nint teste(int n) {\n    while (n > 0) { n -= b; }\n    return a;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        1,
        1,
        1
      ]
    }
  },
  "multi_global_array": {
    "stage": 7,
    "source": "int a[2] = {1, 2}, b = 3;\nint teste(int n) {\n    a[0] = 1;\n    while (a[0] > 0) { a[0]--; n++; }\n    return n + b;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        4,
        5,
        9
      ]
    }
  },
  "multi_array_type": {
    "stage": 7,
    "source": "typedef unsigned Medida;\nint teste(int n) {\n    Medida a[2] = {200, 1}, b[2] = {2, 3};\n    return a[0] + a[1] + b[0] + b[1] + n;\n}\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        206,
        207,
        211
      ],
      "contains": [
        "a = {uint32(200), 1};",
        "b = {uint32(2), 3};"
      ]
    }
  },
  "multi_array_variable_size": {
    "stage": 7,
    "source": "int teste(int n) { int a[n], b[2]; return 0; }\n",
    "case": {
      "diagnostic": "array size must be a positive integer literal"
    }
  },
  "multi_array_partial_init": {
    "stage": 7,
    "source": "int teste(int n) { int a[2] = {1}, b[2] = {2, 3}; return n; }\n",
    "case": {
      "diagnostic": "array initialization must provide all elements"
    }
  },
  "multi_void_variables": {
    "stage": 7,
    "source": "void a, b;\n",
    "case": {
      "diagnostic": "void cannot be used as a variable type"
    }
  },
  "multi_volatile_second": {
    "stage": 7,
    "source": "int teste(int n) {\n    volatile int a = 1, b = 1;\n    while (n > 0) { n -= b; }\n    return a;\n}\n",
    "case": {
      "diagnostic": "while: volatile access"
    }
  },
  "multi_static_second": {
    "stage": 7,
    "source": "int teste(int n) {\n    static int a = 0, b = 0;\n    while (n > 0) { b++; n--; }\n    return a + b;\n}\n",
    "case": {
      "diagnostic": "while: local static variable"
    }
  },
  "multi_bad_leading_comma": {
    "stage": 7,
    "source": "int , a;\n",
    "case": {
      "diagnostic": "syntax error"
    }
  },
  "multi_bad_trailing_comma": {
    "stage": 7,
    "source": "int a,;\n",
    "case": {
      "diagnostic": "syntax error"
    }
  },
  "multi_bad_repeated_type": {
    "stage": 7,
    "source": "int a, int b;\n",
    "case": {
      "diagnostic": "syntax error"
    }
  },
  "multi_pointer_unsupported": {
    "stage": 7,
    "source": "int *a, b;\n",
    "case": {
      "diagnostic": "syntax error"
    }
  },
  "multi_struct_unsupported": {
    "stage": 7,
    "source": "struct S { int valor; };\nstruct S a, b;\n",
    "case": {
      "diagnostic": "multiple declaration: aggregate type is not supported"
    }
  },
  "return_void_if": {
    "stage": 7,
    "source": "int estado = 0;\nvoid ajustar(int n) {\n    estado = 1;\n    if (n < 0) return;\n    estado = 2;\n}\nint teste(int n) { estado = 0; ajustar(n); return estado; }\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        1,
        2,
        2
      ]
    }
  },
  "return_void_else": {
    "stage": 7,
    "source": "int estado = 0;\nvoid ajustar(int n) {\n    if (n < 0) { estado = 1; return; }\n    else { estado = 2; return; }\n}\nint teste(int n) { estado = 0; ajustar(n); return estado; }\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        1,
        2,
        2
      ]
    }
  },
  "return_void_for": {
    "stage": 7,
    "source": "int estado = 0;\nvoid limitar(int n) {\n    int i = 0;\n    for (i = 0; i < n; i++) {\n        if (i == 2) return;\n        estado++;\n    }\n}\nint teste(int n) { estado = 0; limitar(n); return estado; }\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        0,
        1,
        2
      ]
    }
  },
  "return_void_single_while": {
    "stage": 7,
    "source": "int estado = 0;\nvoid limitar(int n) {\n    while (n > 0) return;\n    estado = 9;\n}\nint teste(int n) { estado = 0; limitar(n); return estado; }\n",
    "case": {
      "inputs": [
        0,
        1,
        5
      ],
      "expected": [
        9,
        0,
        0
      ]
    }
  },
  "return_void_typedef": {
    "stage": 7,
    "source": "typedef void Nada;\nint estado = 0;\nNada iniciar(void) { estado = 4; return; }\nint teste(int n) { estado = 0; iniciar(); return estado + n; }\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        2,
        4,
        9
      ]
    }
  },
  "return_void_multi": {
    "stage": 7,
    "source": "int estado = 0;\nvoid definir(int n) {\n    int a = n, b = a + 1;\n    if (a < 0) return;\n    estado = b;\n    return;\n}\nint teste(int n) { estado = 0; definir(n); return estado; }\n",
    "case": {
      "inputs": [
        -2,
        0,
        5
      ],
      "expected": [
        0,
        1,
        6
      ]
    }
  },
  "return_nonvoid_while": {
    "stage": 7,
    "source": "int teste(int n) { while (n > 0) return; return 0; }\n",
    "case": {
      "diagnostic": "return; is only allowed in a void function"
    }
  },
  "return_pointer_nonvoid": {
    "stage": 7,
    "source": "void *teste(void) { return; }\n",
    "case": {
      "diagnostic": "return; is only allowed in a void function"
    }
  },
  "return_nonvoid_typedef": {
    "stage": 7,
    "source": "typedef int Numero; Numero teste(int n) { return; }\n",
    "case": {
      "diagnostic": "return; is only allowed in a void function"
    }
  },
  "return_void_call_value": {
    "stage": 7,
    "source": "void outra(void) {} void iniciar(void) { return outra(); }\n",
    "case": {
      "diagnostic": "a void function cannot return an expression"
    }
  }
}
''')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path.cwd(), help='C2ROB source directory')
    parser.add_argument('--etapa', type=int, choices=(6, 7), default=7, help='Teaching stage to register')
    parser.add_argument('--check', action='store_true', help='Preview changes without writing')
    args = parser.parse_args()
    root = args.root.resolve()
    unit = root / 'test/unit'
    path = unit / 'cases.json'
    if not (root / 'nodes.h').is_file() or not path.is_file():
        parser.error('Run from the C2ROB source root or use --root /path/to/c2rob')
    original = path.read_bytes()
    cases = json.loads(original.decode('utf-8'))
    if not isinstance(cases, dict):
        raise ValueError('cases.json must contain an object indexed by test name')
    selected = {name: data for name, data in TESTS.items() if data['stage'] == args.etapa}

    if args.etapa == 7:
        missing = [name for name, data in TESTS.items() if data['stage'] == 6
                   and (name not in cases or not (unit / (name + '.c')).is_file())]
        if missing:
            raise ValueError('Complete stage 6 first; missing official tests: ' + ', '.join(missing))
        header = (root / 'while_support.h').read_text(encoding='utf-8')
        if 'Kind returnKind' not in header or 'returnKind != Kind::Void' not in header:
            raise ValueError('Complete stage 6 return validation before registering stage 7')

    # Plan and validate the complete operation before making any changes.
    new_files = []
    added = 0
    for name, data in selected.items():
        fixture = unit / (name + '.c')
        expected = data['source'].encode('utf-8')
        if fixture.exists():
            if not fixture.is_file() or fixture.read_bytes() != expected:
                raise ValueError('Existing fixture differs; no files changed: ' + str(fixture))
        else:
            new_files.append((fixture, expected))
        if name in cases:
            if cases[name] != data['case']:
                raise ValueError('Existing case differs; no files changed: ' + name)
        else:
            cases[name] = data['case']
            added += 1

    print(f'Stage {args.etapa}: {len(selected)} tests; {added} new case(s), {len(new_files)} new C file(s).')
    print(f'Official suite after registration: {len(cases)} case(s).')
    if not added and not new_files:
        print('All selected tests are already registered. No files changed.')
        return 0
    if args.check:
        print('Preview only. Run without --check to apply.')
        return 0

    backup = None
    if added:
        stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
        backup = root / f'backup-testes-etapa{args.etapa}-{stamp}'
        backup.mkdir()
        (backup / 'cases.json').write_bytes(original)

    created = []
    try:
        for fixture, content in new_files:
            with fixture.open('xb') as stream:
                created.append(fixture)
                stream.write(content)
        if added:
            path.write_text(json.dumps(cases, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
    except OSError:
        if added:
            path.write_bytes(original)
        for fixture in reversed(created):
            fixture.unlink(missing_ok=True)
        raise

    if backup:
        print('Previous cases.json saved to: ' + str(backup))
    print('Tests registered. Next: make test')
    return 0


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (OSError, ValueError) as error:
        print('Error: ' + str(error), file=sys.stderr)
        sys.exit(1)
