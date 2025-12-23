#include <stdio.h>
#include <stdlib.h>

static int len0;

static int get_len(int x){ int c = 0; do { ++c; x /= 10; } while (x); return c; }

static int has_zero(int x){ while (x){ if (x % 10 == 0) return 1; x /= 10; } return 0; }

static void to_digits(int x, int *d, int *L){ int t = x; int l = get_len(x); *L = l; for (int i = l - 1; i >= 0; --i){ d[i] = t % 10; t /= 10; } }

static int from_digits(int *d, int L){ int v = 0; for (int i = 0; i < L; ++i) v = v * 10 + d[i]; return v; }

int main(void)
{
    int s; if (scanf("%d", &s) != 1) return 0;
    len0 = get_len(s);
    int m; scanf("%d", &m);
    int *dist = (int *)malloc(100000 * sizeof(int));
    for (int i = 0; i < 100000; ++i) dist[i] = -1;
    int *q = (int *)malloc(70000 * sizeof(int));
    int hh = 0, tt = 0;
    dist[s] = 0; q[tt++] = s;
    int d[6], tmp[6];
    while (hh < tt)
    {
        int x = q[hh++];
        int L; to_digits(x, d, &L);
        for (int i = 0; i < L; ++i)
        {
            for (int j = i + 1; j < L; ++j)
            {
                for (int k = 0; k < L; ++k) tmp[k] = d[k];
                int t = tmp[i]; tmp[i] = tmp[j]; tmp[j] = t;
                int y = from_digits(tmp, L);
                if (dist[y] == -1){ dist[y] = dist[x] + 1; q[tt++] = y; }
            }
        }
        if (L >= 2)
        {
            for (int i = 0; i < L; ++i)
            {
                int p = 0; for (int k = 0; k < L; ++k){ if (k == i) continue; tmp[p++] = d[k]; }
                int y = from_digits(tmp, L - 1);
                if (dist[y] == -1){ dist[y] = dist[x] + 1; q[tt++] = y; }
            }
        }
        if (L + 1 <= len0)
        {
            for (int i = 0; i < L - 1; ++i)
            {
                if (d[i] < d[i + 1])
                {
                    for (int xdig = d[i] + 1; xdig <= d[i + 1] - 1; ++xdig)
                    {
                        int p = 0; for (int k = 0; k <= i; ++k) tmp[p++] = d[k]; tmp[p++] = xdig; for (int k = i + 1; k < L; ++k) tmp[p++] = d[k];
                        int y = from_digits(tmp, L + 1);
                        if (dist[y] == -1){ dist[y] = dist[x] + 1; q[tt++] = y; }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int t; scanf("%d", &t);
        if (get_len(t) > len0 || has_zero(t)) { printf("-1\n"); continue; }
        printf("%d\n", dist[t]);
    }
    free(dist); free(q);
    return 0;
}