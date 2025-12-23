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
    int n, T;
    if (scanf("%d %d", &n, &T) != 2) return 0;
    int *I = (int*)malloc((size_t)n * sizeof(int));
    int *t = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d %d", &I[i], &t[i]);
    int *prevRow = (int*)calloc((size_t)T + 1, sizeof(int));
    int *curRow = (int*)calloc((size_t)T + 1, sizeof(int));
    unsigned char *pick = (unsigned char*)calloc((size_t)n * ((size_t)T + 1), sizeof(unsigned char));
    for (int i = 1; i <= n; ++i){
        for (int cap = 0; cap <= T; ++cap) curRow[cap] = prevRow[cap];
        int w = t[i-1], v = I[i-1];
        if (w <= T){
            for (int cap = w; cap <= T; ++cap){
                int cand = prevRow[cap - w] + v;
                if (cand > curRow[cap]){ curRow[cap] = cand; pick[(size_t)(i - 1) * (T + 1) + cap] = 1; }
            }
        }
        int *tmp = prevRow; prevRow = curRow; curRow = tmp;
    }
    printf("%d\n", prevRow[T]);
    int *ans = (int*)malloc((size_t)n * sizeof(int));
    int m = 0;
    int cap = T;
    for (int i = n; i >= 1; --i){
        size_t idx = (size_t)(i - 1) * (T + 1) + cap;
        if (pick[idx]){ ans[m++] = i; cap -= t[i-1]; }
    }
    if (m){
        for (int i = 0; i < m; ++i){
            int k = i;
            for (int j = i + 1; j < m; ++j) if (ans[j] < ans[k]) k = j;
            if (k != i){ int tmp = ans[i]; ans[i] = ans[k]; ans[k] = tmp; }
        }
        for (int i = 0; i < m; ++i){ if (i) putchar(' '); printf("%d", ans[i]); }
        putchar('\n');
    } else {
        putchar('\n');
    }
    free(ans); free(pick); free(curRow); free(prevRow); free(t); free(I);
    return 0;
}