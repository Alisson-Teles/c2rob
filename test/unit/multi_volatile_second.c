int teste(int n) {
    volatile int a = 1, b = 1;
    while (n > 0) { n -= b; }
    return a;
}