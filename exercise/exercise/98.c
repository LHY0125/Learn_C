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
    int n, m, b, mod;
    if (scanf("%d %d %d %d", &n, &m, &b, &mod) != 4) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int B = b + 1;
    int *dp = (int*)calloc((size_t)(m + 1) * (size_t)B, sizeof(int));
    dp[0 * B + 0] = 1 % mod;
    for (int i = 0; i < n; ++i){
        int ai = a[i];
        for (int j = 1; j <= m; ++j){
            for (int k = ai; k <= b; ++k){
                int val = dp[(j - 1) * B + (k - ai)];
                if (val){
                    int *cell = &dp[j * B + k];
                    int sum = *cell + val;
                    if (sum >= mod) sum -= mod;
                    *cell = sum;
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= b; ++k){ ans += dp[m * B + k]; if (ans >= mod) ans -= mod; }
    printf("%d\n", ans);
    free(dp);
    free(a);
    return 0;
}