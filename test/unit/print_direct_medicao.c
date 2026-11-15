#include <stdio.h>

int main(void) {
    float temperatura = 23.5f;
    unsigned int umidade = 64U;
    printf("%s: %.1f C, umidade %u%%\n", "Sala 2", temperatura, umidade);
    return 0;
}
