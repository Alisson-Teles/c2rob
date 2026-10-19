typedef int Numero;
Numero a = 1, b = 2;

int teste(int n) {
    Numero x = n, y = x + a;
    while (y > 0) { y--; }
    return x + b;
}