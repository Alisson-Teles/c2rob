__attribute__ ((noinline))
int inc(int n) {
    return n + 1;
}

int __attribute__(
    (/* spelling accepted by GCC */ __noinline__)
) pilot_definition(int n) {
    return inc(n) + 2;
}
