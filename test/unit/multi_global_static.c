static int a = 1, b = 2;

int teste(int n) {
    while (n > 0) { n -= b; }
    return a;
}