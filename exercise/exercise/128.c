#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v, w; } Edge;

static int cmp_edge(const void *a, const void *b)
{
    const Edge *x = (const Edge *)a;
    const Edge *y = (const Edge *)b;
    return x->w - y->w;
}

static int find(int *fa, int x)
{
    while (fa[x] != x) { fa[x] = fa[fa[x]]; x = fa[x]; }
    return x;
}

int main(void)
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    Edge *E = (Edge *)malloc(((size_t)k + 5) * sizeof(Edge));
    for (int i = 0; i < k; ++i) scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
    qsort(E, (size_t)k, sizeof(Edge), cmp_edge);
    int *fa = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) fa[i] = i;
    long long sum = 0;
    int used = 0;
    for (int i = 0; i < k; ++i)
    {
        int fu = find(fa, E[i].u);
        int fv = find(fa, E[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            sum += E[i].w;
            ++used;
            if (used == n - 1) break;
        }
    }
    if (used != n - 1) printf("-1\n"); else printf("%lld\n", sum);
    free(E); free(fa);
    return 0;
}