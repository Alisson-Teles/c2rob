int estado = 0;

void limitar(int n) {
    while (n > 0) {
        estado++;
        if (estado == 2) return;
        n--;
    }
}

int teste(int n) {
    estado = 0;
    limitar(n);
    return estado;
}