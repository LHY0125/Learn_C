#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int u, v, w; } Edge;

static int cmp_desc(const void *a, const void *b)
{
    const Edge *x = (const Edge *)a;
    const Edge *y = (const Edge *)b;
    return y->w - x->w;
}

static int find(int *fa, int x)
{
    while (fa[x] != x) { fa[x] = fa[fa[x]]; x = fa[x]; }
    return x;
}

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    Edge *E = (Edge *)malloc(((size_t)m + 5) * sizeof(Edge));
    for (int i = 0; i < m; ++i) scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
    qsort(E, (size_t)m, sizeof(Edge), cmp_desc);
    int *fa = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int *head = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    int *to = (int *)malloc(((size_t)(n - 1) * 2 + 5) * sizeof(int));
    int *wt = (int *)malloc(((size_t)(n - 1) * 2 + 5) * sizeof(int));
    int *next = (int *)malloc(((size_t)(n - 1) * 2 + 5) * sizeof(int));
    int idx = 0;
    for (int i = 0; i < m; ++i)
    {
        int fu = find(fa, E[i].u);
        int fv = find(fa, E[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            to[idx] = E[i].v; wt[idx] = E[i].w; next[idx] = head[E[i].u]; head[E[i].u] = idx++;
            to[idx] = E[i].u; wt[idx] = E[i].w; next[idx] = head[E[i].v]; head[E[i].v] = idx++;
        }
    }
    int LOG = 15;
    int *depth = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) depth[i] = -1;
    int *up = (int *)malloc((size_t)LOG * (size_t)(n + 1) * sizeof(int));
    int *mn = (int *)malloc((size_t)LOG * (size_t)(n + 1) * sizeof(int));
    int *q = (int *)malloc(((size_t)n + 5) * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        if (depth[i] != -1) continue;
        int hh = 0, tt = 0; q[tt++] = i; depth[i] = 0; up[i] = i; mn[i] = INT_MAX;
        while (hh < tt)
        {
            int u = q[hh++];
            for (int e = head[u]; e != -1; e = next[e])
            {
                int v = to[e];
                if (depth[v] == -1)
                {
                    depth[v] = depth[u] + 1;
                    up[v] = u;
                    mn[v] = wt[e];
                    q[tt++] = v;
                }
            }
        }
    }
    for (int k = 1; k < LOG; ++k)
    {
        for (int v = 1; v <= n; ++v)
        {
            int p = up[(k - 1) * (n + 1) + v];
            up[k * (n + 1) + v] = up[(k - 1) * (n + 1) + p];
            int a = mn[(k - 1) * (n + 1) + v];
            int b = mn[(k - 1) * (n + 1) + p];
            mn[k * (n + 1) + v] = (a < b) ? a : b;
        }
    }
    int qn; scanf("%d", &qn);
    while (qn--)
    {
        int x, y; scanf("%d %d", &x, &y);
        if (find(fa, x) != find(fa, y)) { puts("-1"); continue; }
        int res = INT_MAX;
        if (depth[x] < depth[y]) { int t = x; x = y; y = t; }
        int diff = depth[x] - depth[y];
        for (int k = LOG - 1; k >= 1; --k)
        {
            int step = 1 << k;
            if (diff >= step)
            {
                int val = mn[k * (n + 1) + x];
                if (val < res) res = val;
                x = up[k * (n + 1) + x];
                diff -= step;
            }
        }
        if (diff)
        {
            int val = mn[x]; if (val < res) res = val; x = up[x];
        }
        if (x == y) { printf("%d\n", res); continue; }
        for (int k = LOG - 1; k >= 1; --k)
        {
            int ux = up[k * (n + 1) + x];
            int uy = up[k * (n + 1) + y];
            if (ux != uy)
            {
                int vx = mn[k * (n + 1) + x]; if (vx < res) res = vx;
                int vy = mn[k * (n + 1) + y]; if (vy < res) res = vy;
                x = ux; y = uy;
            }
        }
        int vx = mn[x]; if (vx < res) res = vx; x = up[x];
        int vy = mn[y]; if (vy < res) res = vy; y = up[y];
        printf("%d\n", res);
    }
    free(E); free(fa); free(head); free(to); free(wt); free(next); free(depth); free(up); free(mn); free(q);
    return 0;
}