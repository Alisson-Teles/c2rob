extern int printf(const char *restrict fmt, ...);

int main(void) {
    int n = 7;
    while (n > 0) {
        n = printf("%u\n", 7U);
        return printf("%d\n", n);
    }
    return 0;
}
