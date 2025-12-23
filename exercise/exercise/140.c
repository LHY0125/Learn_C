#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *nxt = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int *vis = (int *)malloc(((size_t)n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) { nxt[i] = 0; vis[i] = 0; }
    int stamp = 1;
    for (int i = 0; i < m; ++i)
    {
        char op;
        int x, y;
        if (scanf(" %c %d %d", &op, &x, &y) != 3) return 0;
        if (op == 'A')
        {
            nxt[x] = y;
            if (nxt[y] == x) nxt[y] = 0;
        }
        else if (op == 'Q')
        {
            ++stamp;
            int v = x;
            while (v && vis[v] != stamp)
            {
                vis[v] = stamp;
                if (v == y) break;
                v = nxt[v];
            }
            if (v == y) puts("Yes"); else puts("No");
        }
    }
    free(nxt); free(vis);
    return 0;
}