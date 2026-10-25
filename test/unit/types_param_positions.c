unsigned short int somar(
    unsigned short const int a,
    const unsigned short int b
);

unsigned short int somar(
    const unsigned short int a,
    unsigned short int const b
) {
    return a + b;
}

int teste(int n) {
    return somar(n, 2);
}