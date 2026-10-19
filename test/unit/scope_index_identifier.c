int teste(int n) {
    int i = 0, total = 0;
    int a[2] = {3, 7};
    while (n > 0) { int i = 1; total += a[i]; n--; }
    return total + i;
}
