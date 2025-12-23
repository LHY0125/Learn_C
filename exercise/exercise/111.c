#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned int u32;

static int MOD = 99989;

static int powmod(int a, unsigned long long e){
    long long r = 1 % MOD;
    long long x = a % MOD;
    while (e){
        if (e & 1ULL) r = (r * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1ULL;
    }
    return (int)r;
}

static int no_adj(u32 m){ return (m & (m << 1)) == 0U; }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; if (scanf("%d", &n) != 1) return 0;
    int maxH = 0; { int t = n; while (t >= 3){ ++maxH; t /= 3; } ++maxH; }
    int maxA = 0; { int t = n; while (t >= 2){ ++maxA; t /= 2; } }
    if (maxH < 1) maxH = 1;
    if (maxA < 0) maxA = 0;
    u32 **states = (u32**)malloc((size_t)(maxH + 1) * sizeof(u32*));
    int *state_count = (int*)malloc((size_t)(maxH + 1) * sizeof(int));
    for (int h = 1; h <= maxH; ++h){
        int cap = 1 << h;
        u32 *tmp = (u32*)malloc((size_t)cap * sizeof(u32));
        int cnt = 0;
        for (int m = 0; m < cap; ++m){ if (no_adj((u32)m)) tmp[cnt++] = (u32)m; }
        states[h] = (u32*)malloc((size_t)cnt * sizeof(u32));
        for (int i = 0; i < cnt; ++i) states[h][i] = tmp[i];
        state_count[h] = cnt;
        free(tmp);
    }
    unsigned long long ans = 1ULL;
    int r = 1;
    while (r <= n){
        int m = n / r;
        int R = n / m;
        int L = r;
        long long cR = (long long)R - (R / 2) - (R / 3) + (R / 6);
        long long Lm1 = (long long)(L - 1);
        long long cL = Lm1 - (Lm1 / 2) - (Lm1 / 3) + (Lm1 / 6);
        unsigned long long cnt_r = (unsigned long long)(cR - cL);
        int Amax = 0; { int t = m; while (t >= 2){ ++Amax; t /= 2; } }
        int *H = (int*)malloc(((size_t)Amax + 1) * sizeof(int));
        int tm = m;
        for (int a = 0; a <= Amax; ++a){
            int s = tm;
            int hb = 0; while (s >= 3){ ++hb; s /= 3; }
            H[a] = hb + 1;
            tm >>= 1;
        }
        int maxStates = 0;
        for (int a = 0; a <= Amax; ++a){ if (state_count[H[a]] > maxStates) maxStates = state_count[H[a]]; }
        int *dp_cur = (int*)calloc((size_t)maxStates, sizeof(int));
        int *dp_nxt = (int*)calloc((size_t)maxStates, sizeof(int));
        int h0 = H[0];
        for (int i = 0; i < state_count[h0]; ++i){ dp_cur[i] = 1; }
        for (int a = 0; a + 1 <= Amax; ++a){
            int h1 = H[a];
            int h2 = H[a+1];
            int c1 = state_count[h1];
            int c2 = state_count[h2];
            for (int j = 0; j < c2; ++j) dp_nxt[j] = 0;
            u32 *S1 = states[h1];
            u32 *S2 = states[h2];
            for (int i = 0; i < c1; ++i){
                int v = dp_cur[i]; if (!v) continue;
                u32 s1 = S1[i];
                for (int j = 0; j < c2; ++j){
                    u32 s2 = S2[j];
                    if ((s1 & s2) == 0U){
                        int t = dp_nxt[j] + v;
                        if (t >= MOD) t -= MOD;
                        dp_nxt[j] = t;
                    }
                }
            }
            for (int j = 0; j < c2; ++j) dp_cur[j] = dp_nxt[j];
        }
        int hlast = H[Amax];
        int cnt_last = state_count[hlast];
        int f_m = 0; for (int i = 0; i < cnt_last; ++i){ f_m += dp_cur[i]; if (f_m >= MOD) f_m -= MOD; }
        int contrib = powmod(f_m, cnt_r);
        ans = (ans * (unsigned long long)contrib) % MOD;
        free(dp_nxt); free(dp_cur); free(H);
        r = R + 1;
    }
    printf("%u\n", (unsigned int)ans);
    for (int h = 1; h <= maxH; ++h) free(states[h]);
    free(state_count); free(states);
    return 0;
}