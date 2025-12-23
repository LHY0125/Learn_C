#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

typedef struct { ll l, r; } Seg;

static int cmp_seg(const void *a, const void *b){
    const Seg *x = (const Seg*)a, *y = (const Seg*)b;
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
    int n; ll X;
    if (scanf("%d %lld", &n, &X) != 2) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ll *b = (ll*)malloc((size_t)n * sizeof(ll));
    Seg *seg = (Seg*)malloc((size_t)n * sizeof(Seg));
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (cnt > 1) qsort(seg, (size_t)cnt, sizeof(Seg), cmp_seg);
        ll x = a[i];
        for (int j = 0; j < cnt; ++j){
            if (x < seg[j].l) break;
            if (x <= seg[j].r) x = seg[j].r + 1;
        }
        b[i] = x;
        ll L = x - (X - 1);
        ll R = x + (X - 1);
        seg[cnt].l = L;
        seg[cnt].r = R;
        ++cnt;
    }
    for (int i = 0; i < n; ++i){
        if (i) putchar(' ');
        printf("%lld", b[i]);
    }
    putchar('\n');
    free(seg);
    free(b);
    free(a);
    return 0;
}