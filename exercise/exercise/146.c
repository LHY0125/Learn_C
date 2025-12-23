#include <stdio.h>
#include <stdlib.h>

static const long long MOD = 99887765LL;

int main(void)
{
    int n; long long x;
    if (scanf("%d %lld", &n, &x) != 2) return 0;
    int *a = (int *)malloc(((size_t)n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);
    int *st = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int top = 0;
    long long ans = 0;
    long long xmod = x % MOD; if (xmod < 0) xmod += MOD;
    long long pw = 1;
    for (int i = n; i >= 0; --i)
    {
        while (top > 0 && a[st[top - 1]] >= a[i]) --top;
        int bi = (top > 0) ? a[st[top - 1]] : 0;
        long long bmi = bi % MOD; if (bmi < 0) bmi += MOD;
        ans += (bmi * pw) % MOD;
        ans %= MOD;
        if (i > 0) { pw = (pw * xmod) % MOD; }
        st[top++] = i;
    }
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);
    free(a); free(st);
    return 0;
}