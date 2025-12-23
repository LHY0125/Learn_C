#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

static int cmp_int(const void *a, const void *b){
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *t = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    qsort(t, (size_t)n, sizeof(int), cmp_int);
    long long cur = 0, sum = 0;
    for (int i = 0; i < n; ++i){ sum += cur; cur += t[i]; }
    double ans = (double)sum / (double)n;
    printf("%.2f\n", ans);
    free(t);
    return 0;
}