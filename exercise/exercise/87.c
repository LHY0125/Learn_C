#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n,k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    const int MOD = 114584;
    int *dp = (int*)malloc(((size_t)n + 1) * sizeof(int));
    int *pre = (int*)malloc(((size_t)n + 1) * sizeof(int));
    dp[0] = 1;
    pre[0] = 1;
    for (int i = 1; i <= n; ++i){
        long long sum = pre[i-1];
        int idx = i - k - 1;
        if (idx >= 0) sum -= pre[idx];
        int val = (int)(sum % MOD);
        if (val < 0) val += MOD;
        dp[i] = val;
        pre[i] = pre[i-1] + dp[i];
        if (pre[i] >= MOD) pre[i] -= MOD;
    }
    printf("%d\n", dp[n]);
    free(pre);
    free(dp);
    return 0;
}