int estado = 0;

void limitar(int n) {
    while (n > 0) return;
    estado = 9;
}

int teste(int n) { estado = 0; limitar(n); return estado; }