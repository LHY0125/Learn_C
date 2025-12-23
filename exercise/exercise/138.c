#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2)
        return 0;
    char *t = (char *)malloc((size_t)n + 5);
    scanf("%s", t);
    int *pi = (int *)malloc(((size_t)n) * sizeof(int));
    pi[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            ++j;
        pi[i] = j;
    }
    int L = pi[n - 1];
    int add = n - L;
    size_t total = (size_t)n + (size_t)(k - 1) * (size_t)add;
    char *s = (char *)malloc(total + 1);
    memcpy(s, t, (size_t)n);
    size_t pos = (size_t)n;
    for (int i = 1; i < k; ++i)
    {
        memcpy(s + pos, t + L, (size_t)add);
        pos += (size_t)add;
    }
    s[total] = '\0';
    printf("%s\n", s);
    free(t);
    free(pi);
    free(s);
    return 0;
}