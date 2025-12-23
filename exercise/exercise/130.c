#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v; int w; } E;

static int cmp(const void *a, const void *b)
{
    const E *x = (const E *)a; const E *y = (const E *)b;
    return (x->w < y->w) ? -1 : (x->w > y->w);
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
    int *X = (int *)malloc(((size_t)n + 2) * sizeof(int));
    int *Y = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) scanf("%d %d", &X[i], &Y[i]);
    size_t m = (size_t)n * (size_t)(n - 1) / 2;
    E *edges = (E *)malloc((m + 5) * sizeof(E));
    size_t idx = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            long long dx = (long long)X[i] - (long long)X[j];
            long long dy = (long long)Y[i] - (long long)Y[j];
            long long w = dx * dx + dy * dy;
            edges[idx].u = i; edges[idx].v = j; edges[idx].w = (int)w; ++idx;
        }
    }
    qsort(edges, idx, sizeof(E), cmp);
    int *fa = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int comps = n;
    double ans = 0.0;
    for (size_t i = 0; i < idx; ++i)
    {
        int u = edges[i].u, v = edges[i].v;
        int fu = find(fa, u), fv = find(fa, v);
        if (fu != fv)
        {
            if (comps > k)
            {
                fa[fu] = fv;
                --comps;
            }
            else
            {
                ans = (double)edges[i].w;
                break;
            }
        }
    }
    printf("%.2f\n", ans);
    free(X); free(Y); free(edges); free(fa);
    return 0;
}