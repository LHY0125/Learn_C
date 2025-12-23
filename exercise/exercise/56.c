#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static ll sum_min(int L, int n, const int *cnt_le, const ll *sum_le){
    return sum_le[L] + (ll)L * (ll)(n - cnt_le[L]);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    int *e = (int*)malloc((size_t)n * sizeof(int));
    int maxv = 0;
    ll sumE = 0;
    for (int i = 0; i < n; ++i){ scanf("%d", &e[i]); if (e[i] > maxv) maxv = e[i]; sumE += e[i]; }
    if (sumE <= (ll)m){ printf("0\n"); free(e); return 0; }
    int V = maxv + 1;
    int *freq = (int*)calloc((size_t)V, sizeof(int));
    for (int i = 0; i < n; ++i) ++freq[e[i]];
    int *cnt_le = (int*)malloc((size_t)V * sizeof(int));
    ll *sum_le = (ll*)malloc((size_t)V * sizeof(ll));
    ll *sumsq_le = (ll*)malloc((size_t)V * sizeof(ll));
    cnt_le[0] = freq[0];
    sum_le[0] = (ll)0 * (ll)freq[0];
    sumsq_le[0] = (ll)0;
    for (int v = 1; v < V; ++v){
        cnt_le[v] = cnt_le[v-1] + freq[v];
        sum_le[v] = sum_le[v-1] + (ll)v * (ll)freq[v];
        sumsq_le[v] = sumsq_le[v-1] + (ll)v * (ll)v * (ll)freq[v];
    }
    ll S = sumE - (ll)m;
    int lo = 0, hi = maxv, L = 0;
    while (lo <= hi){
        int mid = lo + ((hi - lo) >> 1);
        ll s = sum_min(mid, n, cnt_le, sum_le);
        if (s <= S){ L = mid; lo = mid + 1; } else { hi = mid - 1; }
    }
    ll base_sum = sum_min(L, n, cnt_le, sum_le);
    ll r = S - base_sum;
    ll base_sq = sumsq_le[L] + (ll)L * (ll)L * (ll)(n - cnt_le[L]);
    ll ans = base_sq + r * (ll)(2 * L + 1);
    printf("%lld\n", ans);
    free(sumsq_le);
    free(sum_le);
    free(cnt_le);
    free(freq);
    free(e);
    return 0;
}