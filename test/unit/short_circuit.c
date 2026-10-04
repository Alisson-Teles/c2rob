int chamadas = 0; int tocar(int n) { chamadas++; return n; } int teste(int n) { chamadas = 0; while (n > 0 && tocar(n)) { n--; } return chamadas; }
