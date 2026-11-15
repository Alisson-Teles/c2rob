# include <stdio.h> /* the include stops before this comment */

int next(int n) { return n + 1; }

void log_formato(char *formato, int n) {
    printf(formato, n);
}

int main(void) {
    int n = 3;
    /* print("not a call"); */
    printf /* opening */ (
        "Medição: \"print(fake)\" " "%s %c %u %d %d\n",
        n > 1 ? "sim" : "nao", '(', (unsigned)(next(n) + 4U),
        (int[]){1, 2}[0], n /* ) ] } */ + 1);
    return 0;
}
