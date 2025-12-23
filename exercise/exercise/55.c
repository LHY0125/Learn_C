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
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int *L = (int*)malloc((size_t)n * sizeof(int));
    int *R = (int*)malloc((size_t)n * sizeof(int));
    L[0] = 1;
    for (int i = 1; i < n; ++i){
        if (a[i] > a[i-1]) L[i] = L[i-1] + 1;
        else if (a[i] == a[i-1]) L[i] = L[i-1];
        else L[i] = 1;
    }
    R[n-1] = 1;
    for (int i = n-2; i >= 0; --i){
        if (a[i] > a[i+1]) R[i] = R[i+1] + 1;
        else if (a[i] == a[i+1]) R[i] = R[i+1];
        else R[i] = 1;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i){
        sum += (L[i] > R[i]) ? L[i] : R[i];
    }
    printf("%lld\n", sum);
    free(R);
    free(L);
    free(a);
    return 0;
}