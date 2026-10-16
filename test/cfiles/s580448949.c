#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const double pi = 3.14159265359;
    int a, b, h, m;

    scanf("%d %d %d %d", &a, &b, &h, &m);
    int deg = abs(30 * h - 5.5 * m);

    double power = a * a + b * b - 2 * a * b * cos(pi * deg / 180.0f);
    printf("%.17lf", sqrt(power));
    return 0;
}