#include <stdio.h>

static int n, m;
static int cur[25];

static void dfs(int start, int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; ++i)
        {
            if (i) putchar(' ');
            printf("%d", cur[i]);
        }
        putchar('\n');
        return;
    }
    for (int i = start; i <= n - (m - k) + 1; ++i)
    {
        cur[k] = i;
        dfs(i + 1, k + 1);
    }
}

int main(void)
{
    if (scanf("%d %d", &n, &m) != 2) return 0;
    dfs(1, 0);
    return 0;
}