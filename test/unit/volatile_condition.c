volatile int estado = 0; int teste(int n) { while (estado) { n--; } return n; }
