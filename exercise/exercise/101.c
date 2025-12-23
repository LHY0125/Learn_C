#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

typedef struct { ull l, r; } Interval;

static int cmpL(const void *a, const void *b){
    const Interval *x = (const Interval*)a;
    const Interval *y = (const Interval*)b;
    if (x->l < y->l) return -1;
    if (x->l > y->l) return 1;
    if (x->r < y->r) return -1;
    if (x->r > y->r) return 1;
    return 0;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    size_t cap = 1 << 16;
    size_t n = 0;
    Interval *arr = (Interval*)malloc(cap * sizeof(Interval));
    ull A, B;
    while (scanf("%llu %llu", &A, &B) == 2){
        if (n == cap){
            cap <<= 1;
            Interval *tmp = (Interval*)realloc(arr, cap * sizeof(Interval));
            if (!tmp){ free(arr); return 0; }
            arr = tmp;
        }
        ull l = A < B ? A : B;
        ull r = A > B ? A : B;
        arr[n].l = l;
        arr[n].r = r;
        ++n;
    }
    if (n < 2){
        printf("0\n");
        free(arr);
        return 0;
    }
    qsort(arr, n, sizeof(Interval), cmpL);
    ull ans = 0ULL;
    ull max_r_prev = arr[0].r;
    for (size_t i = 1; i < n; ++i){
        ull l = arr[i].l;
        ull r = arr[i].r;
        ull M = r < max_r_prev ? r : max_r_prev;
        if (M >= l){
            ull len = M - l + 1ULL;
            if (len > ans) ans = len;
        }
        if (r > max_r_prev) max_r_prev = r;
    }
    printf("%llu\n", ans);
    free(arr);
    return 0;
}