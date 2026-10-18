int teste(int n) {
    int a[2] = {0, 2};
    int i = 0;
    while (i < 2) {
        a[n > 0]--;
        i++;
    }
    return a[0] * 10 + a[1];
}