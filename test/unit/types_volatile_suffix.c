int teste(int n) {
    int volatile valor = n;
    return valor;
}