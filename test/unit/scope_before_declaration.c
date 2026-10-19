int teste(int n) {
    int a = n, total = 0;
    while (n > 0) {
        total = a;
        int a = 5, b = a + 2;
        total += a + b;
        n = 0;
    }
    return total + a;
}
