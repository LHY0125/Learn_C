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
    int n,m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *cw = (int*)malloc((size_t)n * sizeof(int));
    int *cb = (int*)malloc((size_t)n * sizeof(int));
    int *cr = (int*)malloc((size_t)n * sizeof(int));
    char *row = (char*)malloc((size_t)m + 5);
    for (int i = 0; i < n; ++i){
        scanf("%s", row);
        int cW=0,cB=0,cR=0;
        for (int j = 0; j < m; ++j){
            char ch = row[j];
            if (ch != 'W') ++cW;
            if (ch != 'B') ++cB;
            if (ch != 'R') ++cR;
        }
        cw[i]=cW; cb[i]=cB; cr[i]=cR;
    }
    int *pW = (int*)malloc(((size_t)n + 1) * sizeof(int));
    int *pB = (int*)malloc(((size_t)n + 1) * sizeof(int));
    int *pR = (int*)malloc(((size_t)n + 1) * sizeof(int));
    pW[0]=0; pB[0]=0; pR[0]=0;
    for (int i = 1; i <= n; ++i){ pW[i]=pW[i-1]+cw[i-1]; pB[i]=pB[i-1]+cb[i-1]; pR[i]=pR[i-1]+cr[i-1]; }
    long long ans = (long long)n * m;
    for (int i = 1; i <= n-2; ++i){
        for (int j = i+1; j <= n-1; ++j){
            long long cur = (long long)pW[i] + (long long)(pB[j] - pB[i]) + (long long)(pR[n] - pR[j]);
            if (cur < ans) ans = cur;
        }
    }
    printf("%lld\n", ans);
    free(pR); free(pB); free(pW);
    free(row);
    free(cr); free(cb); free(cw);
    return 0;
}