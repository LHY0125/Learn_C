#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static int cmp_ll(const void *a, const void *b){
    ll x = *(const ll*)a, y = *(const ll*)b;
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
    ll *q = (ll*)malloc((size_t)(n > 1 ? n - 1 : 0) * sizeof(ll));
    for (int i = 0; i < n - 1; ++i) scanf("%lld", &q[i]);
    ll *s = (ll*)malloc((size_t)n * sizeof(ll));
    s[0] = 0;
    for (int i = 1; i < n; ++i) s[i] = s[i-1] + q[i-1];
    ll *t = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) t[i] = s[i];
    qsort(t, (size_t)n, sizeof(ll), cmp_ll);
    for (int i = 1; i < n; ++i){ if (t[i] == t[i-1]){ printf("-1\n"); free(t); free(s); free(q); return 0; } }
    ll range = t[n-1] - t[0];
    if (range != (ll)n - 1){ printf("-1\n"); free(t); free(s); free(q); return 0; }
    ll shift = 1 - t[0];
    for (int i = 0; i < n; ++i){ ll v = s[i] + shift; printf("%lld%c", v, (i+1==n)?'\n':' '); }
    free(t); free(s); free(q);
    return 0;
}