int chamadas = 0;

int indice(void) {
    chamadas++;
    return 0;
}

int teste(int n) {
    int a[2] = {n, 0};
    chamadas = 0;
    a[indice()]--;
    a[indice()]++;
    return chamadas * 10 + a[0];
}