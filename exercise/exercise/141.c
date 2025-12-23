#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int *next = (int *)malloc(((size_t)n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) next[i] = (i == n) ? 1 : (i + 1);
    int cur = 1, prev = n;
    while (next[cur] != cur)
    {
        for (int c = 1; c < q; ++c)
        {
            prev = cur;
            cur = next[cur];
        }
        next[prev] = next[cur];
        cur = next[cur];
    }
    printf("%d\n", cur);
    free(next);
    return 0;
}