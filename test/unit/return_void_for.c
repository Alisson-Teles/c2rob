int estado = 0;

void limitar(int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (i == 2) return;
        estado++;
    }
}

int teste(int n) { estado = 0; limitar(n); return estado; }