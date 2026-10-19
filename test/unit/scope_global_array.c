int dados[2] = {1, 2};
int teste(int n) {
    int dados[2] = {3, 4}, soma = 0;
    while (n > 0) { soma += dados[1]; n--; }
    return soma;
}
