struct S { int a; int b; }; int teste(int n) { while (n) { struct S s = {1}; n--; } return n; }
