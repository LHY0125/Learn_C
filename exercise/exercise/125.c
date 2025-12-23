#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int v, w, next; } Edge;
typedef struct { long long d; int u; } HN;

static long long *dij(int n, int *head, Edge *E, int src)
{
    long long *dist = (long long *)malloc(((size_t)n + 1) * sizeof(long long));
    for (int i = 1; i <= n; ++i) dist[i] = LLONG_MAX;
    HN *heap = (HN *)malloc(((size_t)n * 4 + 5) * sizeof(HN));
    int hsz = 0;
    dist[src] = 0; heap[hsz++] = (HN){0, src};
    for (int i = hsz - 1; i > 0; --i)
    {
        int p = (i - 1) >> 1;
        if (heap[p].d > heap[i].d) { HN t = heap[p]; heap[p] = heap[i]; heap[i] = t; }
    }
    while (hsz)
    {
        HN cur = heap[0];
        heap[0] = heap[--hsz];
        int i = 0;
        for (;;)
        {
            int l = i * 2 + 1, r = l + 1, s = i;
            if (l < hsz && heap[l].d < heap[s].d) s = l;
            if (r < hsz && heap[r].d < heap[s].d) s = r;
            if (s == i) break;
            HN t = heap[i]; heap[i] = heap[s]; heap[s] = t; i = s;
        }
        long long cd = cur.d; int u = cur.u;
        if (cd != dist[u]) continue;
        for (int e = head[u]; e != -1; e = E[e].next)
        {
            int v = E[e].v; long long nd = cd + (long long)E[e].w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                int k = hsz++;
                heap[k] = (HN){nd, v};
                while (k)
                {
                    int p = (k - 1) >> 1;
                    if (heap[p].d <= heap[k].d) break;
                    HN t = heap[p]; heap[p] = heap[k]; heap[k] = t; k = p;
                }
            }
        }
    }
    free(heap);
    return dist;
}

int main(void)
{
    int N, M, X;
    if (scanf("%d %d %d", &N, &M, &X) != 3) return 0;
    int *h1 = (int *)malloc(((size_t)N + 2) * sizeof(int));
    int *h2 = (int *)malloc(((size_t)N + 2) * sizeof(int));
    Edge *E1 = (Edge *)malloc(((size_t)M + 5) * sizeof(Edge));
    Edge *E2 = (Edge *)malloc(((size_t)M + 5) * sizeof(Edge));
    for (int i = 1; i <= N; ++i) h1[i] = h2[i] = -1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < M; ++i)
    {
        int a, b, t; scanf("%d %d %d", &a, &b, &t);
        E1[c1].v = b; E1[c1].w = t; E1[c1].next = h1[a]; h1[a] = c1++;
        E2[c2].v = a; E2[c2].w = t; E2[c2].next = h2[b]; h2[b] = c2++;
    }
    long long *dx = dij(N, h1, E1, X);
    long long *rx = dij(N, h2, E2, X);
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        long long a = rx[i]; long long b = dx[i];
        if (a == LLONG_MAX || b == LLONG_MAX) continue;
        long long s = a + b;
        if (s > ans) ans = s;
    }
    printf("%lld\n", ans);
    free(h1); free(h2); free(E1); free(E2); free(dx); free(rx);
    return 0;
}