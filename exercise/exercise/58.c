#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static int n, m;

static int ok(ll mid, const int *a){
    ll *pref = (ll*)malloc(((size_t)n + 1) * sizeof(ll));
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + (ll)a[i-1] * 1000LL - mid;
    ll min_pref = 0;
    for (int i = m; i <= n; ++i){
        if (pref[i - m] < min_pref) min_pref = pref[i - m];
        if (pref[i] - min_pref >= 0) { free(pref); return 1; }
    }
    free(pref);
    return 0;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    int maxa = 0;
    for (int i = 0; i < n; ++i){ scanf("%d", &a[i]); if (a[i] > maxa) maxa = a[i]; }
    ll lo = 0, hi = (ll)maxa * 1000LL, ans = lo;
    while (lo <= hi){
        ll mid = lo + ((hi - lo) >> 1);
        if (ok(mid, a)){ ans = mid; lo = mid + 1; } else hi = mid - 1;
    }
    printf("%lld\n", ans);
    free(a);
    return 0;
}