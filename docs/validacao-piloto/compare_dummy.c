#include <stdio.h>
extern void initialise_benchmark(void), warm_caches(int);
extern int benchmark(void), verify_benchmark(int);
int main(void) {
    initialise_benchmark();
    warm_caches(1);
    printf("%d\n", benchmark());
    for (int r = 188; r <= 192; r++) printf("%d\n", verify_benchmark(r));
    return 0;
}
