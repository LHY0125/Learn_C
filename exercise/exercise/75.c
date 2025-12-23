#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static int cmp_double_desc(const void *a, const void *b){
    double x = *(const double*)a, y = *(const double*)b;
    return (y > x) - (y < x);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    double *v = (double*)malloc((size_t)n * sizeof(double));
    double *c = (double*)malloc((size_t)n * sizeof(double));
    for (int i = 0; i < n; ++i) scanf("%lf", &v[i]);
    for (int i = 0; i < n; ++i) scanf("%lf", &c[i]);
    double *s = (double*)malloc((size_t)n * sizeof(double));
    double lo = 0.0, hi = 1000.0;
    for (int it = 0; it < 70; ++it){
        double mid = (lo + hi) * 0.5;
        for (int i = 0; i < n; ++i) s[i] = v[i] - mid * c[i];
        qsort(s, (size_t)n, sizeof(double), cmp_double_desc);
        double sum = 0.0;
        for (int i = 0; i < m; ++i) sum += s[i];
        if (sum >= 0.0) lo = mid; else hi = mid;
    }
    printf("%.3f\n", lo);
    free(s);
    free(c);
    free(v);
    return 0;
}