//Verifica uma chamada sem argumentos na condição do laço.
int chamadas = 0;

int proximo(void) {
    chamadas++;
    return 4 - chamadas;
}

int teste() {
    chamadas = 0;
    int n = 0;

    while (proximo()) {
        n++;
    }

    return chamadas * 10 + n;
}