struct S { int valor; }; int teste(int n) { while (n) { struct S a[1] = {{3}}; n--; } return n; }
