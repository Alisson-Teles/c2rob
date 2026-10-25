unsigned long int dobro(unsigned short int valor);

unsigned long int dobro(unsigned short int valor) {
    return valor + valor;
}

int teste(int n) {
    return dobro(n);
}