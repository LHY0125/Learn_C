// 优化版：每个区间长度 k(1..n) 的最大区间价值 max(subarray_max * subarray_min)
// 算法：最大值笛卡尔树 + 跨越合并（单调两指针），整体显著优于 O(n^2)
// 说明：对每个树节点 i 及其覆盖段 [l,r]，所有包含 i 的子数组最大值均为 a[i]；
//       设从 i 向左取 x 个、向右取 y 个，长度 k=x+y+1，区间最小值为 min(Lmin[x], Rmin[y])；
//       其中 Lmin/Rmin 为以 i 为中心的左/右最小值前后缀。对固定 s=x+y，
//       利用两指针在可行范围内最大化 min(Lmin[s-y], Rmin[y])，O(lenL+lenR) 完成一次合并。

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

static inline ll minll(ll a, ll b) { return a < b ? a : b; }

// 构建“以最大值为堆”的笛卡尔树。相等值用 <= 弹出以保证唯一性（倾向右侧作为父）。
// 输出：left child lc，right child rc，parent；返回根下标。
static int build_cartesian_tree(const ll *a, int n, int *lc, int *rc, int *parent) {
    int *st = (int*)malloc((n + 1) * sizeof(int));
    int top = 0;
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        int last = 0;
        while (top > 0 && a[st[top - 1]] <= a[i]) {
            last = st[--top];
        }
        if (top > 0) {
            rc[st[top - 1]] = i;
            parent[i] = st[top - 1];
        } else {
            root = i;
            parent[i] = 0;
        }
        lc[i] = last;
        if (last) parent[last] = i;
        st[top++] = i;
    }
    free(st);
    return root;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int cap = n + 5;
    int *dq = (int*)malloc((size_t)cap * sizeof(int));
    int head = 0, tail = 0, size = 0;
    char *out = (char*)malloc((size_t)(n * 14 + 1));
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x; scanf("%d", &x);
            head = (head - 1 + cap) % cap;
            dq[head] = x;
            ++size;
        } else if (op == 2) {
            int x; scanf("%d", &x);
            dq[tail] = x;
            tail = (tail + 1) % cap;
            ++size;
        } else if (op == 3) {
            pos += sprintf(out + pos, "%d\n", dq[head]);
        } else if (op == 4) {
            int idx = (tail - 1 + cap) % cap;
            pos += sprintf(out + pos, "%d\n", dq[idx]);
        } else if (op == 5) {
            head = (head + 1) % cap;
            --size;
        } else if (op == 6) {
            tail = (tail - 1 + cap) % cap;
            --size;
        }
    }
    fwrite(out, 1, (size_t)pos, stdout);
    free(out);
    free(dq);
    return 0;
}