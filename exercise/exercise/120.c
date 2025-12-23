#include <stdio.h>

typedef struct { int x, y; } P;

static int n;
static P a[105];
static int vis[105];

static void dfs(int u)
{
    vis[u] = 1;
    for (int v = 0; v < n; ++v)
    {
        if (!vis[v] && (a[v].x == a[u].x || a[v].y == a[u].y))
            dfs(v);
    }
}

int main(void)
{
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &a[i].x, &a[i].y);
    for (int i = 0; i < n; ++i) vis[i] = 0;
    int comp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            ++comp;
            dfs(i);
        }
    }
    printf("%d\n", comp - 1);
    return 0;
}