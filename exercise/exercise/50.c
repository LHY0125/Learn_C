#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

typedef struct { int b; ll c; } Type;

static int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

static int cmp_type(const void *a, const void *b) {
    const Type *x = (const Type*)a, *y = (const Type*)b;
    if (x->b < y->b) return -1;
    if (x->b > y->b) return 1;
    return 0;
}

static int ok(ll L, int n, const int *a, int m, const Type *t, const ll *pref, ll total) {
    for (int i = 0; i < n; ++i) {
        int ai = a[i];
        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (t[mid].b >= ai) r = mid; else l = mid + 1;
        }
        ll need = total - pref[l];
        ll cap = (ll)(n - i) * L;
        if (need > cap) return 0;
    }
    return total <= (ll)n * L;
}

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    Type *t = (Type*)malloc((size_t)m * sizeof(Type));
    for (int i = 0; i < m; ++i) scanf("%d", &t[i].b);
    for (int i = 0; i < m; ++i) scanf("%lld", &t[i].c);
    qsort(a, (size_t)n, sizeof(int), cmp_int);
    qsort(t, (size_t)m, sizeof(Type), cmp_type);
    int maxa = a[n - 1];
    int maxb = t[m - 1].b;
    if (maxb > maxa) {
        printf("-1\n");
        free(t); free(a);
        return 0;
    }
    ll *pref = (ll*)malloc(((size_t)m + 1) * sizeof(ll));
    pref[0] = 0;
    for (int i = 0; i < m; ++i) pref[i + 1] = pref[i] + t[i].c;
    ll total = pref[m];
    ll lo = (total + n - 1) / n, hi = total, ans = hi;
    while (lo <= hi) {
        ll mid = lo + ((hi - lo) >> 1);
        if (ok(mid, n, a, m, t, pref, total)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
    free(pref);
    free(t);
    free(a);
    return 0;
}