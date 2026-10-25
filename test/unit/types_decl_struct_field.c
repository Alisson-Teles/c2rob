struct Dados {
    unsigned short int valor;
};

int teste(int n) {
    struct Dados dados = {3};

    return dados.valor + n;
}