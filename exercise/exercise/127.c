#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n, m; long long L;
    if (scanf("%d %d %lld", &n, &m, &L) != 3) return 0;
    long long *dist = (long long *)malloc((size_t)(n + 1) * (size_t)(n + 1) * sizeof(long long));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[(size_t)i * (n + 1) + j] = (i == j) ? 0LL : LLONG_MAX / 4;
    for (int i = 0; i < m; ++i)
    {
        int u, v; long long c; scanf("%d %d %lld", &u, &v, &c);
        long long *d1 = &dist[(size_t)u * (n + 1) + v];
        long long *d2 = &dist[(size_t)v * (n + 1) + u];
        if (c < *d1) *d1 = c;
        if (c < *d2) *d2 = c;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            long long dik = dist[(size_t)i * (n + 1) + k];
            if (dik == LLONG_MAX / 4) continue;
            for (int j = 1; j <= n; ++j)
            {
                long long skj = dist[(size_t)k * (n + 1) + j];
                if (skj == LLONG_MAX / 4) continue;
                long long alt = dik + skj;
                long long *dij = &dist[(size_t)i * (n + 1) + j];
                if (alt < *dij) *dij = alt;
            }
        }
    }
    unsigned char *reach = (unsigned char *)malloc((size_t)(n + 1) * (size_t)(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            reach[(size_t)i * (n + 1) + j] = (dist[(size_t)i * (n + 1) + j] <= L) ? 1 : 0;
    int *steps = (int *)malloc((size_t)(n + 1) * (size_t)(n + 1) * sizeof(int));
    int *q = (int *)malloc(((size_t)n + 5) * sizeof(int));
    for (int s = 1; s <= n; ++s)
    {
        for (int i = 1; i <= n; ++i) steps[(size_t)s * (n + 1) + i] = -1;
        int hh = 0, tt = 0; q[tt++] = s; steps[(size_t)s * (n + 1) + s] = 0;
        while (hh < tt)
        {
            int u = q[hh++];
            int du = steps[(size_t)s * (n + 1) + u];
            unsigned char *row = &reach[(size_t)u * (n + 1)];
            for (int v = 1; v <= n; ++v)
            {
                if (u == v) continue;
                if (row[v] && steps[(size_t)s * (n + 1) + v] == -1)
                {
                    steps[(size_t)s * (n + 1) + v] = du + 1;
                    q[tt++] = v;
                }
            }
        }
    }
    int qn; scanf("%d", &qn);
    while (qn--)
    {
        int s, t; scanf("%d %d", &s, &t);
        int d = steps[(size_t)s * (n + 1) + t];
        if (d == -1) puts("-1"); else printf("%d\n", d - 1);
    }
    free(dist); free(reach); free(steps); free(q);
    return 0;
}