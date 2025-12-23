#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *head = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    int E = m * 2;
    int *to = (int *)malloc(((size_t)E + 5) * sizeof(int));
    int *next = (int *)malloc(((size_t)E + 5) * sizeof(int));
    int idx = 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b; scanf("%d %d", &a, &b);
        to[idx] = b; next[idx] = head[a]; head[a] = idx++;
        to[idx] = a; next[idx] = head[b]; head[b] = idx++;
    }
    int x; scanf("%d", &x);
    int *dist = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) dist[i] = -1;
    int *q = (int *)malloc(((size_t)n + 5) * sizeof(int));
    int hh = 0, tt = 0;
    dist[x] = 0; q[tt++] = x;
    while (hh < tt)
    {
        int u = q[hh++];
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = to[i];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q[tt++] = v;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dist[i] > ans) ans = dist[i];
    printf("%d\n", ans);
    free(head); free(to); free(next); free(dist); free(q);
    return 0;
}