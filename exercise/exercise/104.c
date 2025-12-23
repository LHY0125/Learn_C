#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

static int M;

static int imin(int a, int b){ return a < b ? a : b; }
static int imax(int a, int b){ return a > b ? a : b; }

static int S;
static int *col;
static int *cnt;
static int *memo;

static int idx(int l, int r, int k){ return ((l - 1) * S + (r - 1)) * M + k; }

static int F(int l, int r, int k){
    if (k >= M) k = M - 1;
    int id = idx(l, r, k);
    int v = memo[id];
    if (v != -1) return v;
    if (l == r){
        int L = cnt[r] + k;
        v = (L >= M) ? 0 : (M - L);
        memo[id] = v;
        return v;
    }
    int need = cnt[r] + k;
    int best = F(l, r - 1, 0) + ((need >= M) ? 0 : (M - need));
    for (int i = l; i <= r - 1; ++i){
        if (col[i] == col[r]){
            int nk = cnt[r] + k;
            if (nk >= M) nk = M - 1;
            int cand = F(l, i, nk) + F(i + 1, r - 1, 0);
            if (cand < best) best = cand;
        }
    }
    memo[id] = best;
    return best;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    char s[256];
    while (scanf("%d", &M) == 1){
        if (scanf("%255s", s) != 1) break;
        int n = (int)strlen(s);
        col = (int*)malloc((size_t)(n + 1) * sizeof(int));
        cnt = (int*)malloc((size_t)(n + 1) * sizeof(int));
        S = 0;
        for (int i = 0; i < n;){
            int j = i;
            while (j < n && s[j] == s[i]) ++j;
            col[++S] = (int)s[i];
            cnt[S] = j - i;
            i = j;
        }
        memo = (int*)malloc((size_t)S * (size_t)S * (size_t)M * sizeof(int));
        for (int i = 0; i < S * S * M; ++i) memo[i] = -1;
        int ans = F(1, S, 0);
        printf("%d\n", ans);
        free(memo); free(cnt); free(col);
    }
    return 0;
}