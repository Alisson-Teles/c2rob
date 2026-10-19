int estado = 0;

void ajustar(int n) {
    estado = 1;
    if (n < 0) return;
    estado = 2;
}

int teste(int n) { estado = 0; ajustar(n); return estado; }