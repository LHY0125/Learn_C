#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

static const int MOD = 1000000007;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int f; if (scanf("%d", &f) != 1) return 0;
    int *ns = (int*)malloc((size_t)f * sizeof(int));
    int maxN = 0;
    for (int i = 0; i < f; ++i){ scanf("%d", &ns[i]); if (ns[i] > maxN) maxN = ns[i]; }
    if (maxN < 0) maxN = 0;
    int *dp1 = (int*)calloc((size_t)maxN + 2, sizeof(int));
    int *dp2 = (int*)calloc((size_t)maxN + 2, sizeof(int));
    if (maxN >= 1){ dp1[1] = 3; dp2[1] = 0; }
    for (int n = 2; n <= maxN; ++n){
        long long a = (2LL * dp1[n-1] + 2LL * dp2[n-1]) % MOD;
        long long b = (1LL * dp1[n-1]) % MOD;
        dp1[n] = (int)a;
        dp2[n] = (int)b;
    }
    for (int i = 0; i < f; ++i){
        int n = ns[i];
        if (n == 0){ printf("1\n"); continue; }
        int ans = dp1[n]; ans += dp2[n]; if (ans >= MOD) ans -= MOD;
        printf("%d\n", ans);
    }
    free(dp2); free(dp1); free(ns);
    return 0;
}