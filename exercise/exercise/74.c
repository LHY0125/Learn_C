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
    int N; ll K;
    if (scanf("%d %lld", &N, &K) != 2) return 0;
    ll *L = (ll*)malloc((size_t)N * sizeof(ll));
    ll maxL = 0;
    for (int i = 0; i < N; ++i){
        scanf("%lld", &L[i]);
        if (L[i] > maxL) maxL = L[i];
    }
    ll lo = 1, hi = maxL, ans = 0;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; ++i){
            cnt += L[i] / mid;
            if (cnt >= K) break;
        }
        if (cnt >= K){ ans = mid; lo = mid + 1; }
        else { hi = mid - 1; }
    }
    printf("%lld\n", ans);
    free(L);
    return 0;
}