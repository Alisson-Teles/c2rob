static int inc(int n) __attribute__((noinline));

static int inc(int n) {
    return n + 1;
}

int call_inc(int n) {
    return inc(n);
}
