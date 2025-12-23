#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

static ull gcdull(ull a, ull b){ while (b){ ull t = a % b; a = b; b = t; } return a; }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; if (scanf("%d", &n) != 1) return 0;
    int maxS = 4 * n;
    ull *dp = (ull*)calloc((size_t)maxS + 1, sizeof(ull));
    dp[0] = 1ULL;
    for (int s = 1; s <= n; ++s){
        ull *nx = (ull*)calloc((size_t)maxS + 1, sizeof(ull));
        int up = 4 * (s - 1);
        for (int j = 0; j <= up; ++j){
            ull v = dp[j]; if (!v) continue;
            nx[j+1] += v;
            nx[j+2] += v;
            nx[j+3] += v;
            nx[j+4] += v;
        }
        free(dp);
        dp = nx;
    }
    ull den = 1ULL << (2 * n);
    ull lose = 0ULL;
    for (int s = 0; s < 2 * n; ++s) lose += dp[s];
    ull win = 0ULL;
    for (int s = 3 * n + 1; s <= 4 * n; ++s) win += dp[s];
    ull g1 = gcdull(lose, den);
    ull g2 = gcdull(win, den);
    printf("%llu/%llu\n", (lose / g1), (den / g1));
    printf("%llu/%llu\n", (win / g2), (den / g2));
    free(dp);
    return 0;
}