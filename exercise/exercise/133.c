#include <stdio.h>
#include <stdlib.h>

static long long target;
static int L;
static int K;
static int found;
static long long ans;

static void gen(int pos, int c4, int c7, long long cur)
{
    if (found) return;
    if (pos == L)
    {
        if (c4 == K && c7 == K && cur >= target)
        {
            ans = cur;
            found = 1;
        }
        return;
    }
    if (c4 < K) gen(pos + 1, c4 + 1, c7, cur * 10 + 4);
    if (!found && c7 < K) gen(pos + 1, c4, c7 + 1, cur * 10 + 7);
}

int main(void)
{
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    target = n;
    int len = 0; long long t = n;
    while (t) { ++len; t /= 10; }
    if (len == 0) len = 1;
    if ((len & 1) == 1)
    {
        L = len + 1; K = L / 2;
        long long cur = 0;
        for (int i = 0; i < K; ++i) cur = cur * 10 + 4;
        for (int i = 0; i < K; ++i) cur = cur * 10 + 7;
        printf("%lld\n", cur);
        return 0;
    }
    L = len; K = L / 2; found = 0; ans = 0;
    gen(0, 0, 0, 0);
    if (found)
    {
        printf("%lld\n", ans);
        return 0;
    }
    L = len + 2; K = L / 2;
    long long cur = 0;
    for (int i = 0; i < K; ++i) cur = cur * 10 + 4;
    for (int i = 0; i < K; ++i) cur = cur * 10 + 7;
    printf("%lld\n", cur);
    return 0;
}