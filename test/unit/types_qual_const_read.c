typedef int const Fixo;

const int base = 2;

int somar(const int valor) {
    const int resultado = valor + base;
    return resultado;
}

int teste(int n) {
    Fixo a = 3;
    const int valores[2] = {4, n + 5};

    if (n) {
        int a = n;
        a += 1;

        return somar(a) + valores[0] + valores[1];
    }

    return somar(a) + valores[0] + valores[1];
}