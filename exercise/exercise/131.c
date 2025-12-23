#include <stdio.h>
#include <stdlib.h>

static int M, N;
static int CAP;
static int *ks, *kn, *kf;
static long long *kv;

static long long dfs(int s, int f, int cur)
{
    if (cur == 0)
        return (s == 0 && f == 0) ? 1LL : 0LL;
    if (s == 0 && f == 0)
        return (cur == 0) ? 1LL : 0LL;
    int h = (((s * 37 + f) * 99991) ^ cur) & (CAP - 1);
    for (;;)
    {
        if (ks[h] == -1)
            break;
        if (ks[h] == s && kn[h] == f && kf[h] == cur)
            return kv[h];
        h = (h + 1) & (CAP - 1);
    }
    long long ans = 0;
    if (s > 0)
        ans += dfs(s - 1, f, cur * 2);
    if (f > 0 && cur >= 2)
        ans += dfs(s, f - 1, cur - 2);
    ks[h] = s; kn[h] = f; kf[h] = cur; kv[h] = ans;
    return ans;
}

int main(void)
{
    if (scanf("%d %d", &M, &N) != 2) return 0;
    CAP = 1 << 20;
    ks = (int *)malloc((size_t)CAP * sizeof(int));
    kn = (int *)malloc((size_t)CAP * sizeof(int));
    kf = (int *)malloc((size_t)CAP * sizeof(int));
    kv = (long long *)malloc((size_t)CAP * sizeof(long long));
    for (int i = 0; i < CAP; ++i) ks[i] = -1;
    long long ans = dfs(M, N, 5);
    printf("%lld\n", ans);
    free(ks); free(kn); free(kf); free(kv);
    return 0;
}