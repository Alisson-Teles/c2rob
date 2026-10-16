#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUERY_PUSH 0
#define QUERY_ACCESS 1
#define QUERY_POP 2

typedef struct Slice {
    int *list;
    int len;
    int size;
} * Slice;

void initSlice(Slice *);
void pushBack(Slice, int);
void randomAccess(Slice, int);
int popBack(Slice);
void freeSlice(Slice);

int main(void)
{
    Slice arr;
    initSlice(&arr);
    int n, query, val;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &query);
        if (query == QUERY_PUSH) {
            scanf("%d", &val);
            pushBack(arr, val);
        } else if (query == QUERY_ACCESS) {
            scanf("%d", &val);
            randomAccess(arr, val);
        } else if (query == QUERY_POP) {
            popBack(arr);
        }
    }
    freeSlice(arr);

    return 0;
}

void initSlice(Slice * s)
{
    *s = (Slice) malloc(sizeof(struct Slice));
    (*s)->len = 0;
    (*s)->size = 0;
    (*s)->list = NULL;
}

void pushBack(Slice s, int x)
{
    if (s->len == s->size) {
        if (s->size)
            s->size *= 2;
        else
            s->size = 2;
        int *tmp = (int *) malloc(s->size * sizeof(int));
        memcpy(tmp, s->list, sizeof(int) * s->len);
        s->list = tmp;
    }
    s->list[s->len++] = x;
}

void randomAccess(Slice s, int p)
{
    printf("%d\n", s->list[p]);
}

int popBack(Slice s)
{
    int x = s->list[--s->len];
    return x;
}

void freeSlice(Slice s)
{
    free(s->list);
    free(s);
}
