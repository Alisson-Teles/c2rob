int a[2] = {1, 2}, b = 3;

int teste(int n) {
    a[0] = 1;
    while (a[0] > 0) { a[0]--; n++; }
    return n + b;
}