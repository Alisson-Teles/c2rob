struct Dados {
    const int valor;
};

int teste(int n) {
    struct Dados dados = {3};

    return dados.valor + n;
}