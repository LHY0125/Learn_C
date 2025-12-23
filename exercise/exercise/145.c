#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    long long *st = (long long *)malloc((size_t)n * sizeof(long long));
    int top = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        long long d, h; scanf("%lld %lld", &d, &h);
        while (top > 0 && st[top - 1] > h) --top;
        if (h > 0 && (top == 0 || st[top - 1] < h)) { st[top++] = h; ++ans; }
    }
    printf("%lld\n", ans);
    free(st);
    return 0;
}