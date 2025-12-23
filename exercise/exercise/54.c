#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

typedef struct { unsigned int a; ll w; } Item;

static int cmp(const void *x, const void *y){
    const Item *u = (const Item*)x, *v = (const Item*)y;
    if (u->a < v->a) return -1;
    if (u->a > v->a) return 1;
    return 0;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Item *arr = (Item*)malloc((size_t)n * sizeof(Item));
    for (int i = 0; i < n; ++i){
        unsigned int a; ll w;
        scanf("%u %lld", &a, &w);
        arr[i].a = a; arr[i].w = w;
    }
    qsort(arr, (size_t)n, sizeof(Item), cmp);
    ll total = 0, sumMax = 0;
    int i = 0;
    while (i < n){
        unsigned int cat = arr[i].a;
        ll mx = arr[i].w;
        total += arr[i].w;
        int j = i + 1;
        while (j < n && arr[j].a == cat){
            if (arr[j].w > mx) mx = arr[j].w;
            total += arr[j].w;
            ++j;
        }
        sumMax += mx;
        i = j;
    }
    ll ans = total - sumMax;
    printf("%lld\n", ans);
    free(arr);
    return 0;
}