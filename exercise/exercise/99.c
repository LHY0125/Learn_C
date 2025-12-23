#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, c;
    if (scanf("%d %d", &n, &c) != 2) return 0;
    int *x = (int*)malloc((size_t)n * sizeof(int));
    int *w = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &w[i]);
    ll *pref = (ll*)malloc(((size_t)n + 1) * sizeof(ll));
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + (ll)w[i-1];
    ll S = pref[n];
    ll INF = (ll)4e18;
    ll *dpL_prev = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *dpR_prev = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *dpL_cur = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *dpR_cur = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    for (int i = 0; i <= n + 1; ++i){ dpL_prev[i] = INF; dpR_prev[i] = INF; dpL_cur[i] = INF; dpR_cur[i] = INF; }
    dpL_prev[c] = 0; dpR_prev[c] = 0;
    for (int len = 2; len <= n; ++len){
        int lmin = c - len + 1; if (lmin < 1) lmin = 1;
        int lmax = c; if (lmax > n - len + 1) lmax = n - len + 1;
        for (int l = lmin; l <= lmax; ++l){
            int r = l + len - 1;
            ll remL = S - (pref[r] - pref[l]);
            ll a1 = dpL_prev[l+1]; if (a1 < INF){ ll d = (ll)(x[l] - x[l-1]); a1 += d * remL; }
            ll a2 = dpR_prev[l+1]; if (a2 < INF){ ll d = (ll)(x[r-1] - x[l-1]); a2 += d * remL; }
            dpL_cur[l] = a1 < a2 ? a1 : a2;
            ll remR = S - (pref[r-1] - pref[l-1]);
            ll b1 = dpL_prev[l]; if (b1 < INF){ ll d = (ll)(x[r-1] - x[l-1]); b1 += d * remR; }
            ll b2 = dpR_prev[l]; if (b2 < INF){ ll d = (ll)(x[r-1] - x[r-2]); b2 += d * remR; }
            dpR_cur[l] = b1 < b2 ? b1 : b2;
        }
        for (int i = lmin; i <= lmax; ++i){ dpL_prev[i] = dpL_cur[i]; dpR_prev[i] = dpR_cur[i]; dpL_cur[i] = INF; dpR_cur[i] = INF; }
    }
    ll ansL = dpL_prev[1];
    ll ansR = dpR_prev[1];
    ll ans = ansL < ansR ? ansL : ansR;
    printf("%lld\n", ans);
    free(dpR_cur); free(dpL_cur); free(dpR_prev); free(dpL_prev); free(pref); free(w); free(x);
    return 0;
}