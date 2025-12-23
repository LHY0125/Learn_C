#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    int E = (n - 1) * 2;
    int *head = (int *)malloc(((size_t)n + 2) * sizeof(int));
    int *to = (int *)malloc(((size_t)E + 5) * sizeof(int));
    int *next = (int *)malloc(((size_t)E + 5) * sizeof(int));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    int idx = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; scanf("%d %d", &u, &v);
        to[idx] = v; next[idx] = head[u]; head[u] = idx++;
        to[idx] = u; next[idx] = head[v]; head[v] = idx++;
    }
    int *color = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) color[i] = -1;
    int *q = (int *)malloc(((size_t)n + 5) * sizeof(int));
    int hh = 0, tt = 0;
    color[1] = 0; q[tt++] = 1;
    while (hh < tt)
    {
        int u = q[hh++];
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = to[i];
            if (color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                q[tt++] = v;
            }
        }
    }
    long long a = 0, b = 0;
    for (int i = 1; i <= n; ++i) if (color[i] == 0) ++a; else ++b;
    long long ans = a * b - (long long)(n - 1);
    printf("%lld\n", ans);
    free(head); free(to); free(next); free(color); free(q);
    return 0;
}