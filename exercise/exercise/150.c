#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    long long *a = (long long *)malloc(((size_t)n + 1) * sizeof(long long));
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    int *L = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int *R = (int *)malloc(((size_t)n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) { int l, r; scanf("%d %d", &l, &r); L[i] = l; R[i] = r; }
    int *stk = (int *)malloc(((size_t)n + 5) * sizeof(int));
    int top = 0;
    int cur = 1;
    int cnt = 0;
    int hasPrev = 0; long long prev = 0;
    while (cur != 0 || top > 0)
    {
        while (cur != 0)
        {
            stk[top++] = cur;
            cur = L[cur];
        }
        cur = stk[--top];
        if (!hasPrev) { prev = a[cur]; hasPrev = 1; }
        else { if (a[cur] <= prev) { printf("No\n"); free(a); free(L); free(R); free(stk); return 0; } prev = a[cur]; }
        ++cnt;
        cur = R[cur];
    }
    if (cnt != n) { printf("No\n"); }
    else { printf("Yes\n"); }
    free(a); free(L); free(R); free(stk);
    return 0;
}