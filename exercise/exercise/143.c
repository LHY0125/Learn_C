#include <stdio.h>
#include <stdlib.h>

typedef struct { int c; int e; } T;

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    T *A = (T *)malloc((size_t)n * sizeof(T));
    T *B = (T *)malloc((size_t)m * sizeof(T));
    for (int i = 0; i < n; ++i) scanf("%d %d", &A[i].c, &A[i].e);
    for (int i = 0; i < m; ++i) scanf("%d %d", &B[i].c, &B[i].e);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i].e == B[j].e)
        {
            int c = A[i].c + B[j].c;
            if (c != 0) printf("%d %d\n", c, A[i].e);
            ++i; ++j;
        }
        else if (A[i].e < B[j].e)
        {
            if (A[i].c != 0) printf("%d %d\n", A[i].c, A[i].e);
            ++i;
        }
        else
        {
            if (B[j].c != 0) printf("%d %d\n", B[j].c, B[j].e);
            ++j;
        }
    }
    while (i < n) { if (A[i].c != 0) printf("%d %d\n", A[i].c, A[i].e); ++i; }
    while (j < m) { if (B[j].c != 0) printf("%d %d\n", B[j].c, B[j].e); ++j; }
    free(A); free(B);
    return 0;
}