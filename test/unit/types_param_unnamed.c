unsigned int dobro(
    unsigned short int,
    unsigned short int
);

unsigned int dobro(
    unsigned short int valor,
    unsigned short int incremento
) {
    return valor + incremento;
}

int teste(int n) {
    return dobro(n, n);
}