#include <stdio.h>

int registradas = 0;

int registrar(int numero) {
    registradas++;
    return 100 + numero;
}

int main(void) {
    int i = 1;
    while (i <= 2) {
        printf("Chamado %d\n", registrar(i));
        i++;
    }
    printf("Registros: %d\n", registradas);
    return registradas != 2;
}
