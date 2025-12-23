#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

static int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *d = (int*)malloc((size_t)n * sizeof(int));
    int *w = (int*)malloc((size_t)m * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &w[i]);
    qsort(d, (size_t)n, sizeof(int), cmp_int);
    qsort(w, (size_t)m, sizeof(int), cmp_int);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (w[j] >= d[i]) { ++i; ++j; }
        else { ++j; }
    }
    printf(i == n ? "YES\n" : "NO\n");
    free(d);
    free(w);
    return 0;
}