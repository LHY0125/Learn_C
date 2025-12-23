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
    ll x,n,m,k;
    if (scanf("%lld %lld %lld %lld", &x, &n, &m, &k) != 4) return 0;
    const int MOD = 1000000007;
    if (x < 0){ printf("impossible\n"); return 0; }
    int X = (int)x;
    int *dp = (int*)malloc(((size_t)X + 1) * sizeof(int));
    for (int i = 0; i <= X; ++i) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= X; ++i){
        long long s = 0;
        if (i - (int)n >= 0) s += dp[i - (int)n];
        if (i - (int)m >= 0) s += dp[i - (int)m];
        if (i - (int)k >= 0) s += dp[i - (int)k];
        dp[i] = (int)(s % MOD);
    }
    if (dp[X] == 0) printf("impossible\n"); else printf("%d\n", dp[X]);
    free(dp);
    return 0;
}