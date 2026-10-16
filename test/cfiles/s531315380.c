#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define REP(i,n) for(i=0;i<n;i++)

int iin() {
    int i;
    scanf("%d", &i);
    return i;
}

long long llin() {
    long long i;
    scanf("%lld", &i);
    return i;
}

double din() {
    double i;
    scanf("%lf", &i);
    return i;
}

char cin() {
    char c;
    scanf("%c", &c);
    return c;
}

void stin(char *s) {
    scanf("%s", s);
}

void iout(int i) {
    printf("%d\n", i);
}

void llout(long long i) {
    printf("%lld\n", i);
}

void dout(double i) {
    printf("%lf\n", i);
}

void cout(char c) {
    printf("%c\n", c);
}

void stout(char *s) {
    printf("%s\n", s);
}

int dfs(int v, int n, int **table, int *visited) {
    int all_visited = 1, i;

    REP(i,n) {
        if (!visited[i]) {
            all_visited = 0;
            break;
        }
    }

    if (all_visited) {
        return 1;
    }

    int count = 0;

    REP(i,n) {
        if (!table[v][i]) continue;
        if (visited[i]) continue;

        visited[i] = 1;
        count += dfs(i, n, table, visited);
        visited[i] = 0;
    }

    return count;
}

int main() {
    int n = iin(), m = iin(), i, a, b;
    int table[N][N];
    memset(table, 0, sizeof table);
    REP(i,m) {
        a = iin();
        b = iin();
        table[a - 1][b - 1] = 1;
        table[b - 1][a - 1] = 1;
    }
    int visited[N];
    memset(visited, 0, sizeof visited);
    int count = dfs(0, n, table, visited);
    iout(count);
    return 0;
}
