struct S { int valor; };
int teste(int n) {
    struct S s = {1};
    int total = 0;
    while (n > 0) {
        struct S s = {3};
        total += s.valor;
        s . valor--;
        n--;
    }
    return total + s . valor;
}
