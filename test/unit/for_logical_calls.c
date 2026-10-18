int chamadas = 0;

int condicao(int n) {
    chamadas++;
    return n;
}

int teste(int n) {
    int i = 0;
    chamadas = 0;
    for (i = 0; (i < n) && condicao(i + 1); i++) {
        chamadas += 0;
    }
    return chamadas * 10 + i;
}