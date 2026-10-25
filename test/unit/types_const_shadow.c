int teste(int n) {
    const int a = 2;

    if (n) {
        int a = 3;
        a += n;

        return a;
    }

    return a;
}