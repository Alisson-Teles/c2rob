struct S { int a; };
int teste(int n) {
    int a = n;
    struct S s = {4};
    while (n > 0) { int a = 2; s.a += a; n--; }
    return a + s.a;
}
