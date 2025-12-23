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
    int N; ll M;
    if (scanf("%d %lld", &N, &M) != 2) return 0;
    ll *h = (ll*)malloc((size_t)N * sizeof(ll));
    ll mx = 0;
    for (int i = 0; i < N; ++i){
        scanf("%lld", &h[i]);
        if (h[i] > mx) mx = h[i];
    }
    ll lo = 0, hi = mx, ans = 0;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        ll got = 0;
        for (int i = 0; i < N; ++i){
            if (h[i] > mid){
                got += h[i] - mid;
                if (got >= M) break;
            }
        }
        if (got >= M){ ans = mid; lo = mid + 1; }
        else { hi = mid - 1; }
    }
    printf("%lld\n", ans);
    free(h);
    return 0;
}