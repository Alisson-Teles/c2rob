typedef unsigned Medida;

int teste(int n) {
    Medida a[2] = {200, 1}, b[2] = {2, 3};
    return a[0] + a[1] + b[0] + b[1] + n;
}