#include <stdio.h>
#include <stdlib.h>

static int CAP;
static int *K;

static int add(int x)
{
    int h = (x * 1315423911u) & (CAP - 1);
    for (;;)
    {
        if (K[h] == -1) { K[h] = x; return 1; }
        if (K[h] == x) return 0;
        h = (h + 1) & (CAP - 1);
    }
}

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    CAP = 1 << 18;
    K = (int *)malloc((size_t)CAP * sizeof(int));
    for (int i = 0; i < CAP; ++i) K[i] = -1;
    int *q = (int *)malloc(1024 * sizeof(int));
    int hh = 0, tt = 0;
    add(n); q[tt++] = n;
    int cnt = 1;
    while (hh < tt)
    {
        int x = q[hh++];
        int t = x;
        while (t >= 10) t /= 10;
        int h = t;
        int m = h / 2;
        int d = 1, y = x;
        while (y >= 10) { d *= 10; y /= 10; }
        for (int k = 1; k <= m; ++k)
        {
            int v = k * d * 10 + x;
            if (add(v)) { if (tt < 1024) q[tt++] = v; ++cnt; }
        }
    }
    printf("%d\n", cnt);
    free(K); free(q);
    return 0;
}