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
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, (size_t)n, sizeof(ll), cmp_ll);
    ll med = a[n/2];
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        ll d = a[i] - med; if (d < 0) d = -d; sum += d;
    }
    printf("%lld\n", sum);
    free(a);
    return 0;
}