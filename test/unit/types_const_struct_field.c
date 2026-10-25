struct S {
    const int v;
};

int teste(int n) {
    struct S s = {3};

    return s.v + n;
}