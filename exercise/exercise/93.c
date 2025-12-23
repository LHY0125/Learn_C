#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n,m; if (scanf("%d %d", &n, &m) != 2) return 0;
    ull **dp = (ull**)malloc(((size_t)m + 1) * sizeof(ull*));
    for (int i = 0; i <= m; ++i) dp[i] = (ull*)calloc((size_t)n, sizeof(ull));
    dp[0][0] = 1ULL;
    for (int s = 0; s < m; ++s){
        for (int p = 0; p < n; ++p){
            ull v = dp[s][p]; if (!v) continue;
            dp[s+1][(p+1)%n] += v;
            dp[s+1][(p-1+n)%n] += v;
        }
    }
    printf("%llu\n", dp[m][0]);
    for (int i = 0; i <= m; ++i) free(dp[i]);
    free(dp);
    return 0;
}