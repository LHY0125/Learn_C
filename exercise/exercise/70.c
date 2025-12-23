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
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int *odd = (int*)malloc((size_t)n * sizeof(int));
    int *even = (int*)malloc((size_t)n * sizeof(int));
    int *odd_pos = (int*)malloc((size_t)n * sizeof(int));
    int *even_pos = (int*)malloc((size_t)n * sizeof(int));
    int oc = 0, ec = 0;
    for (int i = 0; i < n; ++i){
        if ((a[i] & 1) != 0){ odd[oc] = a[i]; odd_pos[oc] = i; ++oc; }
        else { even[ec] = a[i]; even_pos[ec] = i; ++ec; }
    }
    qsort(odd, (size_t)oc, sizeof(int), cmp_int);
    qsort(even, (size_t)ec, sizeof(int), cmp_int);

    int *ans = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < oc; ++i) ans[odd_pos[i]] = odd[i];
    for (int i = 0; i < ec; ++i) ans[even_pos[i]] = even[i];

    for (int i = 0; i < n; ++i){
        if (i) putchar(' ');
        printf("%d", ans[i]);
    }
    putchar('\n');
    free(ans);
    free(even_pos); free(odd_pos);
    free(even); free(odd);
    free(a);
    return 0;
}