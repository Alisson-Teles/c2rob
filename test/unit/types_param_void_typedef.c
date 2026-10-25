typedef void Vazio;

int obter(Vazio) {
    return 4;
}

int teste(int n) {
    return obter() + n;
}