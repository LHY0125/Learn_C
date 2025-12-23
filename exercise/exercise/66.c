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
    int n; ll h; int f;
    if (scanf("%d %lld %d", &n, &h, &f) != 3) return 0;
    ll *diff = (ll*)calloc((size_t)n + 2, sizeof(ll));
    for (int i = 0; i < f; ++i){
        int a,b; scanf("%d %d", &a, &b);
        if (a == b) continue;
        if (a > b){ int t = a; a = b; b = t; }
        int l = a + 1, r = b - 1;
        if (l <= r){ diff[l] += 1; diff[r+1] -= 1; }
    }
    ll cur = 0;
    for (int i = 1; i <= n; ++i){
        cur += diff[i];
        ll ans = h - cur;
        printf("%lld\n", ans);
    }
    free(diff);
    return 0;
}