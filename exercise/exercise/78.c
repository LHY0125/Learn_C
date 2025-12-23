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
    int n; ll t;
    if (scanf("%lld %d", &t, &n) != 2) return 0;
    ll *neg = (ll*)malloc((size_t)n * sizeof(ll));
    ll *pos = (ll*)malloc((size_t)n * sizeof(ll));
    int ln = 0, rn = 0;
    for (int i = 0; i < n; ++i){
        ll x; scanf("%lld", &x);
        if (x < 0) neg[ln++] = -x;
        else pos[rn++] = x;
    }
    qsort(neg, (size_t)ln, sizeof(ll), cmp_ll);
    qsort(pos, (size_t)rn, sizeof(ll), cmp_ll);
    int j = rn;
    ll ans = 0;
    for (int i = 0; i <= ln; ++i){
        ll A = (i == 0 ? 0 : neg[i-1]);
        while (j > 0){
            ll B = pos[j-1];
            ll v1 = 2*A + B;
            ll v2 = A + 2*B;
            ll need = v1 < v2 ? v1 : v2;
            if (need <= t) break;
            --j;
        }
        ll cur = (ll)i + (ll)j;
        if (cur > ans) ans = cur;
    }
    printf("%lld\n", ans);
    free(pos);
    free(neg);
    return 0;
}