#include <stdio.h>
#include <stdlib.h>

static void minPush(long long *h, int *sz, long long v)
{
    int i = (*sz);
    h[i] = v; (*sz)++;
    while (i > 0)
    {
        int p = (i - 1) >> 1;
        if (h[p] <= h[i]) break;
        long long t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}

static long long minPop(long long *h, int *sz)
{
    long long r = h[0];
    int s = --(*sz);
    h[0] = h[s];
    int i = 0;
    while (1)
    {
        int l = (i << 1) | 1, rgt = l + 1, b = i;
        if (l < s && h[l] < h[b]) b = l;
        if (rgt < s && h[rgt] < h[b]) b = rgt;
        if (b == i) break;
        long long t = h[i]; h[i] = h[b]; h[b] = t; i = b;
    }
    return r;
}

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    long long *h = (long long *)malloc((size_t)n * sizeof(long long));
    int sz = 0;
    for (int i = 0; i < n; ++i)
    {
        long long x; scanf("%lld", &x);
        minPush(h, &sz, x);
    }
    long long ans = 0;
    if (sz == 0) { printf("0\n"); free(h); return 0; }
    while (sz > 1)
    {
        long long a = minPop(h, &sz);
        long long b = minPop(h, &sz);
        long long c = a + b;
        ans += c;
        minPush(h, &sz, c);
    }
    printf("%lld\n", ans);
    free(h);
    return 0;
}