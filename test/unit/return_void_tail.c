int estado = 0;
void iniciar(void) { estado = 7; return; }
int teste(int n) { estado = 0; iniciar(); return estado + n; }