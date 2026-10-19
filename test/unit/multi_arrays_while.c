int teste(int n) {
    int soma = 0;
    while (n > 0) {
        int valores[2] = {n, n + 1}, t = valores[0];
        soma += t + valores[1];
        n--;
    }
    return soma;
}