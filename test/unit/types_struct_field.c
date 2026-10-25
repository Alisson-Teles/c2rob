struct Dados {
    unsigned short int valor;
};

int teste(int n) {
    struct Dados d = {250};

    return d.valor + n;
}