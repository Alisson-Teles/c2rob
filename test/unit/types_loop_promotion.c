int teste(int n) {
    unsigned short i = 0;
    int total = 0;

    while (i < n) {
        total += i;
        i++;
    }

    return total;
}