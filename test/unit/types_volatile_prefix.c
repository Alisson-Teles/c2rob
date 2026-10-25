int teste(int n) {
    volatile unsigned int a = n;

    return a;
}