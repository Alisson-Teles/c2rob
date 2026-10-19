int teste(int n) {
    int i = 0, total = 0;
    for (i = 0; i < n; i++) {
        int a = i, b = a + 1;
        total += a + b;
    }
    return total;
}