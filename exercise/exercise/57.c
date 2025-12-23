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

static int lower_bound_ll(const ll *arr, int n, ll x){
    int l = 0, r = n;
    while (l < r){
        int m = (l + r) >> 1;
        if (arr[m] < x) l = m + 1; else r = m;
    }
    return l;
}

static ll *bit; static int B;
static void bit_add(int i, ll v){ for (; i <= B; i += i & -i) bit[i] += v; }
static ll bit_sum(int i){ ll s = 0; for (; i > 0; i -= i & -i) s += i ? bit[i] : 0; return s; }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; ll t;
    if (scanf("%d %lld", &n, &t) != 2) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ll *pref = (ll*)malloc(((size_t)n + 1) * sizeof(ll));
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + (a[i-1] - t);
    ll *comp = (ll*)malloc(((size_t)n + 1) * sizeof(ll));
    for (int i = 0; i <= n; ++i) comp[i] = pref[i];
    qsort(comp, (size_t)n + 1, sizeof(ll), cmp_ll);
    int m = 0;
    for (int i = 0; i <= n; ++i){ if (i == 0 || comp[i] != comp[i-1]) comp[m++] = comp[i]; }
    B = m;
    bit = (ll*)calloc((size_t)B + 1, sizeof(ll));
    const ll MOD = 1000000007LL;
    ll ans = 0;
    for (int j = 0; j <= n; ++j){
        int idx = lower_bound_ll(comp, m, pref[j]) + 1;
        ll cnt = bit_sum(idx);
        ans += cnt;
        if (ans >= MOD) ans %= MOD;
        bit_add(idx, 1);
    }
    printf("%lld\n", ans % MOD);
    free(bit);
    free(comp);
    free(pref);
    free(a);
    return 0;
}