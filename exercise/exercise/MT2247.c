#include <stdio.h>
#include <limits.h>

static int n;
static int a[8][8];
static int best;
static int vis[8];

static void dfs(int u, int cnt, int cur)
{
    if (cur >= best) return;
    if (cnt == n)
    {
        int tot = cur + a[u][0];
        if (tot < best) best = tot;
        return;
    }
    for (int v = 1; v < n; ++v)
    {
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v, cnt + 1, cur + a[u][v]);
            vis[v] = 0;
        }
    }
}

int main(void)
{
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i) vis[i] = 0;
    best = INT_MAX;
    vis[0] = 1;
    dfs(0, 1, 0);
    printf("%d\n", best);
    return 0;
}