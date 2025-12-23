#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    if (m == 0) { printf("0\n"); return 0; }
    long long *a = (long long *)malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    long long *p = (long long *)malloc(((size_t)n + 1) * sizeof(long long));
    p[0] = 0;
    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i - 1];
    int *dq = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int head = 0, tail = 0;
    dq[tail++] = 0;
    long long ans = p[1] - p[0];
    for (int i = 1; i <= n; ++i)
    {
        while (head < tail && dq[head] < i - m) ++head;
        if (head < tail)
        {
            long long val = p[i] - p[dq[head]];
            if (val > ans) ans = val;
        }
        while (head < tail && p[dq[tail - 1]] >= p[i]) --tail;
        dq[tail++] = i;
    }
    printf("%lld\n", ans);
    free(a); free(p); free(dq);
    return 0;
}