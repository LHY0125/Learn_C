#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

typedef struct { ll a, b; } Item;

static int cmp_item(const void *p, const void *q){
    const Item *x = (const Item*)p, *y = (const Item*)q;
    if (x->a < y->a) return -1;
    if (x->a > y->a) return 1;
    if (x->b < y->b) return -1;
    if (x->b > y->b) return 1;
    return 0;
}

static void heap_push(ll *h, int *sz, ll v){
    int i = ++(*sz);
    h[i] = v;
    while (i > 1){
        int p = i >> 1;
        if (h[p] >= h[i]) break;
        ll t = h[p]; h[p] = h[i]; h[i] = t;
        i = p;
    }
}

static ll heap_top(ll *h){ return h[1]; }

static void heap_pop(ll *h, int *sz){
    int n = *sz;
    h[1] = h[n];
    --(*sz);
    int i = 1;
    while (1){
        int l = i << 1, r = l + 1, m = i;
        if (l <= *sz && h[l] > h[m]) m = l;
        if (r <= *sz && h[r] > h[m]) m = r;
        if (m == i) break;
        ll t = h[m]; h[m] = h[i]; h[i] = t;
        i = m;
    }
}

static int lower_bound_a(ll *A, int n, ll val){
    int l = 1, r = n, ans = n + 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (A[mid] >= val){ ans = mid; r = mid - 1; }
        else l = mid + 1;
    }
    return ans;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    ll v; int n, m;
    if (scanf("%lld %d %d", &v, &n, &m) != 3) return 0;
    Item *it = (Item*)malloc(((size_t)n + 1) * sizeof(Item));
    for (int i = 1; i <= n; ++i){
        scanf("%lld %lld", &it[i].a, &it[i].b);
    }
    qsort(it + 1, (size_t)n, sizeof(Item), cmp_item);
    ll *A = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *B = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    for (int i = 1; i <= n; ++i){ A[i] = it[i].a; B[i] = it[i].b; }
    ll INF = 9000000000000000000LL;
    int k = m / 2;
    ll *prefK = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *sufK = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *prefK1 = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *sufK1 = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    for (int i = 0; i <= n + 1; ++i){ prefK[i] = INF; sufK[i] = INF; prefK1[i] = INF; sufK1[i] = INF; }
    if (k == 0){ for (int i = 0; i <= n + 1; ++i){ prefK[i] = 0; sufK[i] = 0; } }
    else{
        ll *heap = (ll*)malloc(((size_t)n + 5) * sizeof(ll)); int sz = 0; ll sum = 0;
        for (int i = 1; i <= n; ++i){
            heap_push(heap, &sz, B[i]); sum += B[i];
            if (sz > k){ sum -= heap_top(heap); heap_pop(heap, &sz); }
            if (sz == k) prefK[i] = sum; else prefK[i] = INF;
        }
        sz = 0; sum = 0;
        for (int i = n; i >= 1; --i){
            heap_push(heap, &sz, B[i]); sum += B[i];
            if (sz > k){ sum -= heap_top(heap); heap_pop(heap, &sz); }
            if (sz == k) sufK[i] = sum; else sufK[i] = INF;
        }
        free(heap);
    }
    int k1 = k - 1;
    if (k1 <= 0){ for (int i = 0; i <= n + 1; ++i){ prefK1[i] = 0; sufK1[i] = 0; } }
    else{
        ll *heap = (ll*)malloc(((size_t)n + 5) * sizeof(ll)); int sz = 0; ll sum = 0;
        for (int i = 1; i <= n; ++i){
            heap_push(heap, &sz, B[i]); sum += B[i];
            if (sz > k1){ sum -= heap_top(heap); heap_pop(heap, &sz); }
            if (sz == k1) prefK1[i] = sum; else prefK1[i] = INF;
        }
        sz = 0; sum = 0;
        for (int i = n; i >= 1; --i){
            heap_push(heap, &sz, B[i]); sum += B[i];
            if (sz > k1){ sum -= heap_top(heap); heap_pop(heap, &sz); }
            if (sz == k1) sufK1[i] = sum; else sufK1[i] = INF;
        }
        free(heap);
    }
    ll *leftCostWith = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *rightCostWith = (ll*)malloc(((size_t)n + 2) * sizeof(ll));
    ll *suffixMin = (ll*)malloc(((size_t)n + 3) * sizeof(ll));
    for (int i = 1; i <= n; ++i){
        if (prefK1[i-1] >= INF/2) leftCostWith[i] = INF; else leftCostWith[i] = prefK1[i-1] + B[i];
    }
    for (int j = 1; j <= n; ++j){
        if (sufK1[j+1] >= INF/2) rightCostWith[j] = INF; else rightCostWith[j] = B[j] + sufK1[j+1];
    }
    suffixMin[n+1] = INF;
    for (int j = n; j >= 1; --j){
        ll vmin = rightCostWith[j];
        if (suffixMin[j+1] < vmin) vmin = suffixMin[j+1];
        suffixMin[j] = vmin;
    }
    ll lo = 0, hi = A[n], ans = 0;
    while (lo <= hi){
        ll mid = (lo + hi) >> 1;
        int ok = 0;
        if ((m & 1) != 0){
            for (int i = 1; i <= n; ++i){
                if (A[i] < mid) continue;
                ll left = prefK[i-1];
                ll right = sufK[i+1];
                if (left >= INF/2 || right >= INF/2) continue;
                ll cost = left + right + B[i];
                if (cost <= v){ ok = 1; break; }
            }
        } else {
            for (int i = 1; i <= n; ++i){
                if (leftCostWith[i] >= INF/2) continue;
                ll need = 2*mid - A[i];
                int j = lower_bound_a(A, n, need);
                if (j <= i) j = i + 1;
                if (j > n) continue;
                ll rc = suffixMin[j];
                if (rc >= INF/2) continue;
                ll cost = leftCostWith[i] + rc;
                if (cost <= v){ ok = 1; break; }
            }
        }
        if (ok){ ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    printf("%lld\n", ans);
    free(suffixMin);
    free(rightCostWith);
    free(leftCostWith);
    free(sufK1);
    free(prefK1);
    free(sufK);
    free(prefK);
    free(B);
    free(A);
    free(it);
    return 0;
}