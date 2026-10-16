//Verifica o for dentro de uma função sem parâmetros.
int teste(void) {
    int i = 0;
    int soma = 0;

    for (i = 0; i < 4; i++) {
        soma += i;
    }

    return soma;
}