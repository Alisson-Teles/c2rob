int dobro(int x) { return 2 * x; }
int teste(int n) {
    int x = n, total = 0;
    while (n > 0) { int x = 3; total += dobro(x); n--; }
    return total + x;
}
