int teste(int n) {
    static int contador = 0;
    contador++;

    return n + contador;
}