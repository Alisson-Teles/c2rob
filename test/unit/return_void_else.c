int estado = 0;

void ajustar(int n) {
    if (n < 0) { estado = 1; return; }
    else { estado = 2; return; }
}

int teste(int n) { estado = 0; ajustar(n); return estado; }