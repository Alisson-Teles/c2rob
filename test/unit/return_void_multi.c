int estado = 0;

void definir(int n) {
    int a = n, b = a + 1;
    if (a < 0) return;
    estado = b;
    return;
}

int teste(int n) { estado = 0; definir(n); return estado; }