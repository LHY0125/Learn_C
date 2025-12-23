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
    int n, X;
    if (scanf("%d %d", &n, &X) != 2) return 0;
    int *c = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    int *dp = (int*)calloc((size_t)X + 1, sizeof(int));
    for (int i = 0; i < n; ++i){
        int w = c[i] * (n - i);
        if (w > X) continue;
        for (int cap = X; cap >= w; --cap){
            int v = dp[cap - w] + 1;
            if (v > dp[cap]) dp[cap] = v;
        }
    }
    printf("%d\n", dp[X]);
    free(dp);
    free(c);
    return 0;
}