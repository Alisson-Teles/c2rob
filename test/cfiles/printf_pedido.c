#include <stdio.h>

int main(void) {
    int quantidade = 3;
    int preco_unitario = 12;

    printf("Pedido recebido\n");
    printf("Itens: %d | Total: R$ %d\n", quantidade, quantidade * preco_unitario);
    return 0;
}