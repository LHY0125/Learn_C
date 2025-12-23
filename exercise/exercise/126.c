#include <stdio.h>
#include <stdlib.h>

typedef struct { int v, next; } E;

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    int *a = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int m = 2 * (n - 1) + n;
    int *head = (int *)malloc(((size_t)n + 2) * sizeof(int));
    E *e = (E *)malloc(((size_t)m + 5) * sizeof(E));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    int idx = 0;
    for (int i = 1; i < n; ++i)
    {
        e[idx].v = i + 1; e[idx].next = head[i]; head[i] = idx++;
        e[idx].v = i;     e[idx].next = head[i + 1]; head[i + 1] = idx++;
    }
    for (int i = 1; i <= n; ++i)
    {
        int v = a[i];
        e[idx].v = v; e[idx].next = head[i]; head[i] = idx++;
    }
    int *dist = (int *)malloc(((size_t)n + 2) * sizeof(int));
    for (int i = 1; i <= n; ++i) dist[i] = -1;
    int *q = (int *)malloc(((size_t)n + 5) * sizeof(int));
    int hh = 0, tt = 0; q[tt++] = 1; dist[1] = 0;
    while (hh < tt)
    {
        int u = q[hh++];
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q[tt++] = v;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1) putchar(' ');
        printf("%d", dist[i]);
    }
    putchar('\n');
    free(a); free(head); free(e); free(dist); free(q);
    return 0;
}