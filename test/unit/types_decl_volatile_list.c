int teste(int n) {
    unsigned int volatile a = 0, b = n;

    while (b) {
        b--;
    }

    return n;
}