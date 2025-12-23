#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static int cmp_ll_asc(const void *a, const void *b){
    ll x = *(const ll*)a, y = *(const ll*)b;
    return (x > y) - (x < y);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    ll *x = (ll*)malloc((size_t)N * sizeof(ll));
    for (int i = 0; i < N; ++i) scanf("%lld", &x[i]);
    qsort(x, (size_t)N, sizeof(ll), cmp_ll_asc);
    ll lo = 0, hi = x[N-1] - x[0], ans = 0;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        int cnt = 1;
        ll last = x[0];
        for (int i = 1; i < N; ++i){
            if (x[i] - last >= mid){
                ++cnt;
                last = x[i];
                if (cnt >= M) break;
            }
        }
        if (cnt >= M){ ans = mid; lo = mid + 1; }
        else { hi = mid - 1; }
    }
    printf("%lld\n", ans);
    free(x);
    return 0;
}