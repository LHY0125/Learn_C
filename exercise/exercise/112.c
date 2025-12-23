#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

static int MOD = 99989;

static int popcnt(int x){
    int c = 0;
    while (x){ x &= (x - 1); ++c; }
    return c;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    int Smax = 1 << N;
    int *okrow = (int*)malloc((size_t)Smax * sizeof(int));
    int *bits = (int*)malloc((size_t)Smax * sizeof(int));
    int *list = (int*)malloc((size_t)Smax * sizeof(int));
    int cntS = 0;
    for (int m = 0; m < Smax; ++m){
        if ((m & (m << 1)) == 0){ okrow[m] = 1; bits[m] = popcnt(m); list[cntS++] = m; } else { okrow[m] = 0; bits[m] = popcnt(m); }
    }
    char **ok = (char**)malloc((size_t)cntS * sizeof(char*));
    for (int i = 0; i < cntS; ++i) ok[i] = (char*)malloc((size_t)cntS * sizeof(char));
    for (int i = 0; i < cntS; ++i){
        int a = list[i];
        for (int j = 0; j < cntS; ++j){
            int b = list[j];
            int bad = (a & b) | (a & (b << 1)) | (a & (b >> 1));
            ok[i][j] = (bad == 0) ? 1 : 0;
        }
    }
    int **dp_prev = (int**)malloc((size_t)cntS * sizeof(int*));
    int **dp_cur = (int**)malloc((size_t)cntS * sizeof(int*));
    for (int i = 0; i < cntS; ++i){ dp_prev[i] = (int*)calloc((size_t)M + 1, sizeof(int)); dp_cur[i] = (int*)calloc((size_t)M + 1, sizeof(int)); }
    for (int i = 0; i < cntS; ++i){ int b = bits[list[i]]; if (b <= M) dp_prev[i][b] = 1; }
    for (int r = 1; r < N; ++r){
        for (int j = 0; j < cntS; ++j){ for (int k = 0; k <= M; ++k) dp_cur[j][k] = 0; }
        for (int i = 0; i < cntS; ++i){
            for (int j = 0; j < cntS; ++j){ if (!ok[i][j]) continue; int add = bits[list[j]]; for (int k = 0; k + add <= M; ++k){ int v = dp_prev[i][k]; if (!v) continue; int t = dp_cur[j][k + add] + v; if (t >= MOD) t -= MOD; dp_cur[j][k + add] = t; } }
        }
        for (int j = 0; j < cntS; ++j){ for (int k = 0; k <= M; ++k) dp_prev[j][k] = dp_cur[j][k]; }
    }
    int ans = 0;
    for (int i = 0; i < cntS; ++i){ int v = dp_prev[i][M]; ans += v; if (ans >= MOD) ans -= MOD; }
    printf("%d\n", ans);
    for (int i = 0; i < cntS; ++i){ free(dp_prev[i]); free(dp_cur[i]); free(ok[i]); }
    free(dp_prev); free(dp_cur); free(ok); free(list); free(bits); free(okrow);
    return 0;
}