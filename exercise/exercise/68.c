#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static int cmp_ll(const void *a, const void *b){
    ll x = *(const ll*)a, y = *(const ll*)b;
    return (x > y) - (x < y);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    ll *b = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    ll *d = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) d[i] = a[i] - b[i];
    qsort(d, (size_t)n, sizeof(ll), cmp_ll);
    int ok = 1;
    for (int i = 0; i < n/2; ++i){
        if (d[i] + d[n-1-i] != 0){ ok = 0; break; }
    }
    printf(ok ? "YES\n" : "NO\n");
    free(d);
    free(b);
    free(a);
    return 0;
}