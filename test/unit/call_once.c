int chamadas = 0; int limite = 0; int proximo(int n) { chamadas++; return chamadas <= n; } int teste(int n) { chamadas = 0; int i = 0; while (proximo(n)) { i++; } return chamadas * 10 + i; }
