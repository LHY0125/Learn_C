#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    unsigned int N = (1u << (n + 1)) - 1u;
    long long *w = (long long *)malloc(((size_t)N + 2) * sizeof(long long));
    long long *mx = (long long *)malloc(((size_t)N + 2) * sizeof(long long));
    for (unsigned int i = 1; i <= N; ++i)
        scanf("%lld", &w[i]);
    unsigned int first_leaf = (N >> 1) + 1u;
    for (unsigned int i = first_leaf; i <= N; ++i)
        mx[i] = w[i];
    long long add = 0;
    for (int i = (int)(first_leaf - 1u); i >= 1; --i)
    {
        long long L = mx[i << 1];
        long long R = mx[(i << 1) | 1];
        add += (L >= R) ? (L - R) : (R - L);
        mx[i] = w[i] + ((L >= R) ? L : R);
    }
    printf("%lld\n", add);
    free(w);
    free(mx);
    return 0;
}