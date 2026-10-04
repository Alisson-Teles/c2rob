int teste(int n) { while (n) { volatile int estado = 0; n--; } return n; }
