#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    int *a = (int *)malloc((size_t)n * (size_t)n * sizeof(int));
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int v; scanf("%d", &v);
            a[i * n + j] = v;
            if (v == 2) { sx = i; sy = j; }
        }
    }
    int *dist = (int *)malloc((size_t)n * (size_t)n * sizeof(int));
    unsigned char *vis = (unsigned char *)malloc((size_t)n * (size_t)n);
    for (int i = 0; i < n * n; ++i) { dist[i] = -1; vis[i] = 0; }
    int *q = (int *)malloc(((size_t)n * (size_t)n + 5) * sizeof(int));
    int hh = 0, tt = 0;
    int sidx = sx * n + sy;
    dist[sidx] = 0; vis[sidx] = 1; q[tt++] = sidx;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
    while (hh < tt)
    {
        int idx = q[hh++];
        int x = idx / n; int y = idx % n;
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d]; int ny = y + dy[d];
            if (nx < 0) nx = n - 1; else if (nx >= n) nx = 0;
            if (ny < 0) ny = n - 1; else if (ny >= n) ny = 0;
            int nidx = nx * n + ny;
            if (vis[nidx]) continue;
            if (a[nidx] == 0) continue;
            vis[nidx] = 1;
            dist[nidx] = dist[idx] + 1;
            q[tt++] = nidx;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int idx = i * n + j;
            int out = (dist[idx] <= 0) ? 0 : dist[idx];
            if (j) putchar(' ');
            printf("%d", out);
        }
        putchar('\n');
    }
    free(a); free(dist); free(vis); free(q);
    return 0;
}