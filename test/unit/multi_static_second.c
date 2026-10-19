int teste(int n) {
    static int a = 0, b = 0;
    while (n > 0) { b++; n--; }
    return a + b;
}