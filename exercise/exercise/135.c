#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int K, N, M;
    if (scanf("%d %d %d", &K, &N, &M) != 3) return 0;
    int total = K * N * M;
    char *A = (char *)malloc((size_t)total);
    for (int z = 0; z < K; ++z)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                char c;
                do { if (scanf(" %c", &c) != 1) return 0; } while (c != '.' && c != '#');
                A[z * N * M + i * M + j] = c;
            }
    int sx, sy; if (scanf("%d %d", &sx, &sy) != 2) return 0;
    int *q = (int *)malloc((size_t)(total + 5) * sizeof(int));
    unsigned char *vis = (unsigned char *)malloc((size_t)total);
    for (int i = 0; i < total; ++i) vis[i] = 0;
    int hh = 0, tt = 0;
    int sidx = 0 * N * M + (sx - 1) * M + (sy - 1);
    q[tt++] = sidx; vis[sidx] = 1;
    int infected = 1;
    const int dz[6] = {1,-1,0,0,0,0};
    const int dx[6] = {0,0,1,-1,0,0};
    const int dy[6] = {0,0,0,0,1,-1};
    while (hh < tt)
    {
        int idx = q[hh++];
        int z = idx / (N * M);
        int rem = idx % (N * M);
        int x = rem / M;
        int y = rem % M;
        for (int d = 0; d < 6; ++d)
        {
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nz < 0 || nz >= K || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int nidx = nz * N * M + nx * M + ny;
            if (vis[nidx]) continue;
            if (A[nidx] == '.')
            {
                vis[nidx] = 1;
                q[tt++] = nidx;
                ++infected;
            }
        }
    }
    printf("%d\n", infected);
    free(A); free(q); free(vis);
    return 0;
}