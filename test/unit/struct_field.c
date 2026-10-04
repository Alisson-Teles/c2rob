struct S { int valor; }; int teste(int n) { struct S s = {3}; int i = 0; while (s.valor) { s.valor--; i++; } return i; }
