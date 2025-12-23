#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

static int cmp_desc(const void *a, const void *b){
    int x = *(const int*)a, y = *(const int*)b;
    return (y > x) - (y < x);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n,k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    qsort(a, (size_t)n, sizeof(int), cmp_desc);
    int threshold = a[k-1];
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] >= threshold && a[i] > 0) ++cnt;
    }
    printf("%d\n", cnt);
    free(a);
    return 0;
}