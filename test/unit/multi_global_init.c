int total = 0, limite = 3;

int teste(int n) {
    total = 0;
    while (total < limite && total < n) { total++; }
    return total;
}