#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long *a = (long long*)malloc((size_t)n * sizeof(long long));
    long long sum = 0;
    for (int i = 0; i < n; ++i) { scanf("%lld", &a[i]); sum += a[i]; }
    long long avg = sum / n;

    long long *s = (long long*)malloc((size_t)n * sizeof(long long));
    long long cur = 0;
    for (int i = 0; i < n; ++i) { cur += a[i] - avg; s[i] = cur; }

    long long *t = (long long*)malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) t[i] = s[i];
    int cmp(const void *x, const void *y) {
        long long ux = *(const long long*)x, uy = *(const long long*)y;
        return (ux > uy) - (ux < uy);
    }
    qsort(t, (size_t)n, sizeof(long long), cmp);
    long long med = t[n/2];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long d = s[i] - med; if (d < 0) d = -d; ans += d;
    }
    printf("%lld\n", ans);

    free(t);
    free(s);
    free(a);
    return 0;
}