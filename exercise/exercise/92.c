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
    int nodes = n + 2;
    ll *dp = (ll*)malloc((size_t)nodes * sizeof(ll));
    for (int i = 0; i < nodes; ++i) dp[i] = (ll)4e18;
    dp[0] = 0;
    for (int i = 0; i <= n; ++i){
        int len = n + 1 - i;
        for (int k = 1; k <= len; ++k){
            ll x; scanf("%lld", &x);
            int j = i + k;
            ll cand = dp[i] + x;
            if (cand < dp[j]) dp[j] = cand;
        }
    }
    printf("%lld\n", dp[n+1]);
    free(dp);
    return 0;
}