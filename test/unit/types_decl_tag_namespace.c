struct Palavra {
    unsigned short int valor;
};

typedef int Palavra;

int teste(int n) {
    struct Palavra dados = {3};
    Palavra total = n;

    return dados.valor + total;
}