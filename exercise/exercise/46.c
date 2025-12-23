#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { long long w, s; long long key; } Man;

static int cmp(const void *a, const void *b) {
    const Man *x = (const Man*)a, *y = (const Man*)b;
    if (x->key < y->key) return -1;
    if (x->key > y->key) return 1;
    return 0;
}

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Man *a = (Man*)malloc((size_t)n * sizeof(Man));
    for (int i = 0; i < n; ++i) {
        long long w, s;
        scanf("%lld %lld", &w, &s);
        a[i].w = w; a[i].s = s; a[i].key = w + s;
    }
    qsort(a, (size_t)n, sizeof(Man), cmp);
    long long pref = 0, ans = -((long long)1<<62);
    for (int i = 0; i < n; ++i) {
        long long risk = pref - a[i].s;
        if (risk > ans) ans = risk;
        pref += a[i].w;
    }
    printf("%lld\n", ans);
    free(a);
    return 0;
}