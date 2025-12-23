#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int v, w, next; } Edge;
typedef struct { long long d; int u, m; } HN;

static int n, m, p;
static int *head;
static Edge *E;
static int ec;
static int *pc, *pa, *pb, *pt;

static HN *heap;
static int hsz;

static void hpush(HN x)
{
    int i = hsz++;
    heap[i] = x;
    while (i)
    {
        int p = (i - 1) >> 1;
        if (heap[p].d <= heap[i].d) break;
        HN t = heap[p]; heap[p] = heap[i]; heap[i] = t; i = p;
    }
}

static HN hpop()
{
    HN r = heap[0];
    heap[0] = heap[--hsz];
    int i = 0;
    for (;;)
    {
        int l = i * 2 + 1, rgt = l + 1, s = i;
        if (l < hsz && heap[l].d < heap[s].d) s = l;
        if (rgt < hsz && heap[rgt].d < heap[s].d) s = rgt;
        if (s == i) break;
        HN t = heap[i]; heap[i] = heap[s]; heap[s] = t; i = s;
    }
    return r;
}

int main(void)
{
    if (scanf("%d %d %d", &n, &m, &p) != 3) return 0;
    head = (int *)malloc(((size_t)n + 2) * sizeof(int));
    E = (Edge *)malloc(((size_t)m * 2 + 5) * sizeof(Edge));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    ec = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        E[ec].v = v; E[ec].w = w; E[ec].next = head[u]; head[u] = ec++;
        E[ec].v = u; E[ec].w = w; E[ec].next = head[v]; head[v] = ec++;
    }
    pc = (int *)malloc(((size_t)p + 2) * sizeof(int));
    pa = (int *)malloc(((size_t)p + 2) * sizeof(int));
    pb = (int *)malloc(((size_t)p + 2) * sizeof(int));
    pt = (int *)malloc(((size_t)p + 2) * sizeof(int));
    for (int i = 0; i < p; ++i)
    {
        int c, a, b, t; scanf("%d %d %d %d", &c, &a, &b, &t);
        pc[i] = c; pa[i] = a; pb[i] = b; pt[i] = t;
    }
    int M = 1 << p;
    long long *dist = (long long *)malloc(((size_t)n * (size_t)M) * sizeof(long long));
    for (size_t i = 0; i < (size_t)n * (size_t)M; ++i) dist[i] = LLONG_MAX;
    heap = (HN *)malloc(((size_t)n * (size_t)M + 5) * sizeof(HN));
    hsz = 0;
    dist[(0) * (size_t)n + (size_t)(1 - 1)] = 0;
    hpush((HN){0LL, 1, 0});
    while (hsz)
    {
        HN cur = hpop();
        long long cd = cur.d; int u = cur.u; int mask = cur.m;
        if (cd != dist[(size_t)mask * (size_t)n + (size_t)(u - 1)]) continue;
        if (u == n)
        {
            printf("%lld\n", cd);
            free(head); free(E); free(pc); free(pa); free(pb); free(pt); free(dist); free(heap);
            return 0;
        }
        for (int i = head[u]; i != -1; i = E[i].next)
        {
            int v = E[i].v; long long nd = cd + (long long)E[i].w;
            size_t idx = (size_t)mask * (size_t)n + (size_t)(v - 1);
            if (nd < dist[idx]) { dist[idx] = nd; hpush((HN){nd, v, mask}); }
        }
        for (int i = 0; i < p; ++i)
        {
            int bit = 1 << i;
            if (!(mask & bit) && u == pc[i])
            {
                int nmask = mask | bit;
                size_t idx = (size_t)nmask * (size_t)n + (size_t)(u - 1);
                if (cd < dist[idx]) { dist[idx] = cd; hpush((HN){cd, u, nmask}); }
            }
            if (mask & bit)
            {
                if (u == pa[i])
                {
                    int v = pb[i]; long long nd = cd + (long long)pt[i];
                    size_t idx = (size_t)mask * (size_t)n + (size_t)(v - 1);
                    if (nd < dist[idx]) { dist[idx] = nd; hpush((HN){nd, v, mask}); }
                }
                if (u == pb[i])
                {
                    int v = pa[i]; long long nd = cd + (long long)pt[i];
                    size_t idx = (size_t)mask * (size_t)n + (size_t)(v - 1);
                    if (nd < dist[idx]) { dist[idx] = nd; hpush((HN){nd, v, mask}); }
                }
            }
        }
    }
    return 0;
}