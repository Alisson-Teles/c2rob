int teste(int n) {
    int a[2] = {1, 2}, x = 3;
    while (n > 0) {
        int a[2] = {4, 5}, x = 6;
        a[0]++;
        x++;
        n--;
    }
    return a[0] + a[1] + x;
}
