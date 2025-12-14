// 地道连通查询（线性房屋 1..n）：支持操作
// D x: 摧毁房屋 x；R: 修复上一次摧毁的房屋；Q x: 询问士兵在 x 能到达的房屋数
// 思路：维护“被摧毁房屋”的有序集合，查询时找离 x 最近的左右两个摧毁位置。
// 为了在 C 中高效实现前驱/后继，使用树状数组(Fenwick)存放摧毁标记（1 表示摧毁），
// 并用“按前缀和查找第 k 个 1”的技巧 O(log n) 求出前驱/后继位置。

#include <stdio.h>
#include <stdlib.h>

static int N;          // 房屋总数
static int *bit;       // 树状数组，1..N
static int *dead;      // 摧毁标记
static int *stackD;    // 摧毁栈，支持 R
static int topD = 0;

static inline int lowbit(int x) { return x & -x; }

static void bit_add(int i, int delta) {
    for (; i <= N; i += lowbit(i)) bit[i] += delta;
}

static int bit_sum(int i) {
    int s = 0;
    for (; i > 0; i -= lowbit(i)) s += bit[i];
    return s;
}

// 返回使得前缀和等于 k 的最小下标（1..N）。要求 k>=1 且 k<=sum(N)
static int bit_find_kth(int k) {
    int idx = 0;
    // 最大 2 的幂覆盖到 N
    int p = 1;
    while ((p << 1) <= N) p <<= 1;
    for (; p; p >>= 1) {
        int next = idx + p;
        if (next <= N && bit[next] < k) {
            idx = next;
            k -= bit[next];
        }
    }
    return idx + 1; // 1..N
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    N = n;
    bit = (int *)calloc((size_t)N + 1u, sizeof(int));
    dead = (int *)calloc((size_t)N + 2u, sizeof(int));
    stackD = (int *)malloc(((size_t)m + 5u) * sizeof(int));
    if (!bit || !dead || !stackD) return 0;

    for (int i = 0; i < m; ++i) {
        char cmd[8];
        if (scanf("%7s", cmd) != 1) break;
        if (cmd[0] == 'D') {
            int x; scanf("%d", &x);
            if (x >= 1 && x <= n && !dead[x]) {
                dead[x] = 1;
                bit_add(x, +1);
                stackD[topD++] = x;
            }
        } else if (cmd[0] == 'R') {
            if (topD > 0) {
                int x = stackD[--topD];
                if (dead[x]) { dead[x] = 0; bit_add(x, -1); }
            }
        } else if (cmd[0] == 'Q') {
            int x; scanf("%d", &x);
            if (x < 1 || x > n) { printf("0\n"); continue; }
            if (dead[x]) {
                printf("0\n");
            } else {
                int left_cnt = bit_sum(x - 1);
                int total_cnt = bit_sum(n);
                int upto_x_cnt = bit_sum(x);
                int left_break = (left_cnt == 0) ? 0 : bit_find_kth(left_cnt);
                int right_break = (upto_x_cnt == total_cnt) ? (n + 1) : bit_find_kth(upto_x_cnt + 1);
                int reachable = right_break - left_break - 1;
                printf("%d\n", reachable);
            }
        }
    }

    free(bit); free(dead); free(stackD);
    return 0;
}