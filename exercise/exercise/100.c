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
    int n; if (scanf("%d", &n) != 1) return 0;
    int a, b; if (scanf("%d %d", &a, &b) != 2) return 0;
    int *val = (int*)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    ll *dp = (ll*)malloc((size_t)(n + 1) * sizeof(ll));
    for (int i = 0; i <= n; ++i) dp[i] = (ll)4e18;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i){
        int mn = val[i], mx = val[i];
        for (int j = i; j >= 1; --j){
            if (val[j] < mn) mn = val[j];
            if (val[j] > mx) mx = val[j];
            ll cost = dp[j-1] + (ll)a + (ll)b * (ll)(mx - mn) * (ll)(mx - mn);
            if (cost < dp[i]) dp[i] = cost;
        }
    }
    printf("%lld\n", dp[n]);
    free(dp); free(val);
    return 0;
}