int chamadas = 0; int tocar(int n) { chamadas++; return n; } int teste(int n) { chamadas = 0; int i = 0; while (i < n || tocar(0)) { i++; } return chamadas * 10 + i; }
