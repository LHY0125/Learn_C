#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static ll *seg;
static ll *lazyTag;

static inline ll minll(ll a, ll b){ return a < b ? a : b; }

static void build(int idx, int l, int r, ll *arr){
    if (l == r){ seg[idx] = arr[l]; return; }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid, arr);
    build(idx<<1|1, mid+1, r, arr);
    seg[idx] = minll(seg[idx<<1], seg[idx<<1|1]);
}

static inline void apply(int idx, ll val){ seg[idx] += val; lazyTag[idx] += val; }

static inline void pushDown(int idx){
    ll tag = lazyTag[idx];
    if (tag != 0){
        apply(idx<<1, tag);
        apply(idx<<1|1, tag);
        lazyTag[idx] = 0;
    }
}

static void range_add(int idx, int l, int r, int L, int R, ll val){
    if (L <= l && r <= R){ apply(idx, val); return; }
    pushDown(idx);
    int mid = (l + r) >> 1;
    if (L <= mid) range_add(idx<<1, l, mid, L, R, val);
    if (R > mid) range_add(idx<<1|1, mid+1, r, L, R, val);
    seg[idx] = minll(seg[idx<<1], seg[idx<<1|1]);
}

static ll range_min(int idx, int l, int r, int L, int R){
    if (L <= l && r <= R) return seg[idx];
    pushDown(idx);
    int mid = (l + r) >> 1;
    ll res = (ll)0x7fffffffffffffffLL;
    if (L <= mid){ ll v = range_min(idx<<1, l, mid, L, R); res = minll(res, v); }
    if (R > mid){ ll v = range_min(idx<<1|1, mid+1, r, L, R); res = minll(res, v); }
    return res;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    ll *r = (ll*)malloc(((size_t)n + 1) * sizeof(ll));
    for (int i = 1; i <= n; ++i) scanf("%lld", &r[i]);
    seg = (ll*)calloc(((size_t)4*n + 5), sizeof(ll));
    lazyTag = (ll*)calloc(((size_t)4*n + 5), sizeof(ll));
    build(1, 1, n, r);
    int bad = 0, badId = -1;
    for (int j = 1; j <= m; ++j){
        ll d; int s, t;
        if (scanf("%lld %d %d", &d, &s, &t) != 3) { bad = 1; badId = j; break; }
        ll mn = range_min(1, 1, n, s, t);
        if (mn >= d){ range_add(1, 1, n, s, t, -d); }
        else { bad = 1; badId = j; break; }
    }
    if (!bad){ printf("0\n"); }
    else { printf("-1\n%d\n", badId); }
    free(lazyTag);
    free(seg);
    free(r);
    return 0;
}