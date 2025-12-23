#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = (char *)malloc(1000005);
    if (scanf("%1000000s", s) != 1) return 0;
    int n = (int)strlen(s);
    int *pi = (int *)malloc((size_t)n * sizeof(int));
    pi[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    int L = pi[n - 1];
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) if (pi[i] > mx) mx = pi[i];
    while (L > 0 && mx < L) L = pi[L - 1];
    if (L == 0)
    {
        printf("Just a legend\n");
    }
    else
    {
        s[L] = '\0';
        printf("%s\n", s);
    }
    free(pi); free(s);
    return 0;
}