typedef void Nada;
int estado = 0;

Nada iniciar(void) { estado = 4; return; }

int teste(int n) { estado = 0; iniciar(); return estado + n; }