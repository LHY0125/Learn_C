#include <stdio.h>

static int parent[105][105];
static unsigned char used[105];

static int findc(int c, int x)
{
    int p = parent[c][x];
    while (p != x)
    {
        int gp = parent[c][p];
        parent[c][x] = gp;
        x = p;
        p = gp;
    }
    return x;
}

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int c = 1; c <= m; ++c)
    {
        for (int i = 1; i <= n; ++i)
            parent[c][i] = i;
        used[c] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        used[c] = 1;
        int rx = findc(c, x);
        int ry = findc(c, y);
        if (rx != ry) parent[c][rx] = ry;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        int ans = 0;
        for (int c = 1; c <= m; ++c)
        {
            if (!used[c]) continue;
            int ru = findc(c, u);
            int rv = findc(c, v);
            if (ru == rv) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}