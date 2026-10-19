int chamadas = 0;
int proximo(void) { chamadas++; return chamadas; }

int teste(int n) {
    chamadas = 0;
    int a = proximo(), b = proximo(), c = proximo();
    return a * 100 + b * 10 + c + chamadas;
}