int chamadas = 0;
int indice(void) { chamadas++; return 0; }
int teste(int n) {
    int a[1] = {1};
    chamadas = 0;
    while (n > 0) {
        int a[1] = {2}, b = 0;
        a[indice()]++;
        n--;
    }
    return a[0] + chamadas;
}
