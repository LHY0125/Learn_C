#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

static const int MOD = 1000000007;

typedef struct { int c; int s; int q; } Node;

static ull digits[32];

static ull solve(ull n){
    if (n == (ull)-1) return 0ULL;
    int L = 0;
    if (n == 0ULL){ digits[L++] = 0ULL; }
    else { while (n){ digits[L++] = n % 10ULL; n /= 10ULL; } for (int i = 0, j = L - 1; i < j; ++i, --j){ ull t = digits[i]; digits[i] = digits[j]; digits[j] = t; } }
    static Node dp[2][2][2][6][6];
    static Node nx[2][2][2][6][6];
    for (int t = 0; t < 2; ++t) for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) for (int m = 0; m < 6; ++m) for (int r = 0; r < 6; ++r){ dp[t][a][b][m][r].c = 0; dp[t][a][b][m][r].s = 0; dp[t][a][b][m][r].q = 0; }
    dp[1][1][0][0][0].c = 1;
    dp[1][1][0][0][0].s = 0;
    dp[1][1][0][0][0].q = 0;
    for (int pos = 0; pos < L; ++pos){
        int lim = (int)digits[pos];
        for (int t = 0; t < 2; ++t) for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) for (int m = 0; m < 6; ++m) for (int r = 0; r < 6; ++r){ nx[t][a][b][m][r].c = 0; nx[t][a][b][m][r].s = 0; nx[t][a][b][m][r].q = 0; }
        for (int t = 0; t < 2; ++t){
            int up = t ? lim : 9;
            for (int a = 0; a < 2; ++a){
                for (int b = 0; b < 2; ++b){
                    for (int m = 0; m < 6; ++m){
                        for (int r = 0; r < 6; ++r){
                            Node cur = dp[t][a][b][m][r];
                            if (!cur.c && !cur.s && !cur.q) continue;
                            for (int d = 0; d <= up; ++d){
                                int nt = (t && (d == up)) ? 1 : 0;
                                int na = (a && d == 0) ? 1 : 0;
                                int nb = b || (d == 6);
                                int nm = (m * 10 + d) % 6;
                                int nr = (r + d) % 6;
                                Node *dst = &nx[nt][na][nb][nm][nr];
                                int cadd = cur.c;
                                int sadd = (int)((10LL * cur.s + (long long)cadd * d) % MOD);
                                int qadd = (int)((100LL * cur.q + (20LL * d % MOD) * cur.s + (long long)cadd * (long long)d * (long long)d) % MOD);
                                dst->c += cadd; if (dst->c >= MOD) dst->c -= MOD;
                                dst->s += sadd; if (dst->s >= MOD) dst->s -= MOD;
                                dst->q += qadd; if (dst->q >= MOD) dst->q -= MOD;
                            }
                        }
                    }
                }
            }
        }
        for (int t = 0; t < 2; ++t) for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) for (int m = 0; m < 6; ++m) for (int r = 0; r < 6; ++r){ dp[t][a][b][m][r] = nx[t][a][b][m][r]; }
    }
    long long ans = 0;
    for (int t = 0; t < 2; ++t){
        for (int a = 0; a < 2; ++a){
            for (int b = 0; b < 2; ++b){
                if (b) continue;
                for (int m = 0; m < 6; ++m){
                    if (m == 0) continue;
                    for (int r = 0; r < 6; ++r){
                        if (r == 0) continue;
                        ans += dp[t][a][b][m][r].q;
                        if (ans >= MOD) ans -= MOD;
                    }
                }
            }
        }
    }
    return (ull)ans;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int T; if (scanf("%d", &T) != 1) return 0;
    while (T--){
        unsigned long long a, b; scanf("%llu %llu", &a, &b);
        ull x = solve(b);
        ull y = solve(a - 1ULL);
        ull ans = (x >= y) ? (x - y) : (x + MOD - y);
        printf("%llu\n", ans);
    }
    return 0;
}