#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

typedef struct { ll x; ll a; } Item;

static int cmp_item(const void *p, const void *q){
    const Item *A = (const Item*)p;
    const Item *B = (const Item*)q;
    if (A->x < B->x) return -1;
    if (A->x > B->x) return 1;
    return 0;
}

static int upper_less_ll(const ll *arr, int n, ll key){
    int l = 1, r = n, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if (arr[m] < key){ ans = m; l = m + 1; }
        else r = m - 1;
    }
    return ans;
}

typedef struct { int val; int idx; } Node;

static Node *seg;
static int N;

static Node merge(Node a, Node b){
    if (a.val >= b.val) return a; else return b;
}

static void build(int p, int l, int r, const int *R){
    if (l == r){ seg[p].val = R[l]; seg[p].idx = l; return; }
    int m = (l + r) >> 1;
    build(p<<1, l, m, R);
    build(p<<1|1, m+1, r, R);
    seg[p] = merge(seg[p<<1], seg[p<<1|1]);
}

static Node query(int p, int l, int r, int ql, int qr){
    if (ql <= l && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    if (qr <= m) return query(p<<1, l, m, ql, qr);
    if (ql > m) return query(p<<1|1, m+1, r, ql, qr);
    Node a = query(p<<1, l, m, ql, qr);
    Node b = query(p<<1|1, m+1, r, ql, qr);
    return merge(a, b);
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; if (scanf("%d", &n) != 1) return 0;
    Item *arr = (Item*)malloc((size_t)(n + 1) * sizeof(Item));
    for (int i = 1; i <= n; ++i){ ll xi, ai; scanf("%lld %lld", &xi, &ai); arr[i].x = xi; arr[i].a = ai; }
    qsort(arr + 1, n, sizeof(Item), cmp_item);
    ll *xs = (ll*)malloc((size_t)(n + 1) * sizeof(ll));
    for (int i = 1; i <= n; ++i) xs[i] = arr[i].x;
    int *R = (int*)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i){ ll key = arr[i].x + arr[i].a; R[i] = upper_less_ll(xs, n, key); }
    N = n; seg = (Node*)malloc((size_t)(4 * N + 8) * sizeof(Node));
    build(1, 1, N, R);
    int *E = (int*)calloc((size_t)(n + 2), sizeof(int));
    for (int i = 1; i <= n; ++i){
        int t = i;
        int stsz = 0;
        int *stack = (int*)malloc((size_t)(n - i + 2) * sizeof(int));
        while (E[t] == 0){
            int rt = R[t];
            Node nd = query(1, 1, N, t, rt);
            if (nd.val == rt){ E[t] = rt + 1; break; }
            stack[stsz++] = t;
            t = nd.idx;
        }
        int res = E[t];
        while (stsz){ E[stack[--stsz]] = res; }
        free(stack);
    }
    const int MOD = 998244353;
    int *dp = (int*)calloc((size_t)(n + 2), sizeof(int));
    dp[n+1] = 1;
    for (int i = n; i >= 1; --i){
        int a1 = dp[i+1];
        int a2 = dp[E[i]];
        int s = a1 + a2; if (s >= MOD) s -= MOD;
        dp[i] = s;
    }
    printf("%d\n", dp[1]);
    free(dp); free(E); free(seg); free(R); free(xs); free(arr);
    return 0;
}