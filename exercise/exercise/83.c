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

static ll count_leq(ll *a, int n, ll d){
    ll cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i){
        while (a[i] - a[j] > d) ++j;
        cnt += (ll)(i - j);
    }
    return cnt;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; ll k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, (size_t)n, sizeof(ll), cmp_ll);
    ll lo = 0, hi = a[n-1] - a[0], ans = hi;
    while (lo <= hi){
        ll mid = lo + ((hi - lo) >> 1);
        ll cnt = count_leq(a, n, mid);
        if (cnt >= k){ ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
    free(a);
    return 0;
}