// 随机连续子序列的最小值期望满意度：
// 选取所有子数组(连续子序列)均匀随机；score 为该子数组的最小值；满意度为 max(0, score - expect)
// 目标：对每个 expect 求 E[max(0, min - expect)]，用最简分数输出。
// 做法：
// - 用单调栈统计每个位置作为“子数组最小值的代表”的子数组个数 c_i，采用去重规则：
//   prev 为前一个 < 当前值的位置，next 为后一个 <= 当前值的位置；贡献个数为 (i-prev)*(next-i)
// - 将相同值的贡献累加，得到“最小值为 v 的子数组个数” count[v]
// - 总子数组数 T = n*(n+1)/2；对 expect=e，有
//   E = (1/T) * sum_{v>e} (v-e) * count[v]
//   = (1/T) * ( sum_{v>e} v*count[v] - e * sum_{v>e} count[v] )
// - 预先按 v 排序并做前缀和，查询时二分找 v>e 的起点，O(log n) 得到分子；化简为最简分数输出。

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

typedef struct { ll v; ull c; } Pair;

static int cmp_pair(const void *a, const void *b) {
    const Pair *x = (const Pair *)a, *y = (const Pair *)b;
    if (x->v < y->v) return -1;
    if (x->v > y->v) return 1;
    return 0;
}

static void print_u128(u128 x) {
    if (x == 0) { putchar('0'); return; }
    char buf[64];
    int p = 0;
    while (x) {
        unsigned int d = (unsigned int)(x % 10);
        buf[p++] = (char)('0' + d);
        x /= 10;
    }
    while (p--) putchar(buf[p]);
}

static ull gcd_ull(ull a, ull b) {
    while (b) { ull t = a % b; a = b; b = t; }
    return a;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int n; if (scanf("%d", &n) != 1) return 0;
        ll *a = (ll *)malloc(((size_t)n + 5u) * sizeof(ll));
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);

        // 单调栈：prev(<) 与 next(<=)
        int *prev = (int *)malloc(((size_t)n + 5u) * sizeof(int));
        int *next = (int *)malloc(((size_t)n + 5u) * sizeof(int));
        int *st = (int *)malloc(((size_t)n + 5u) * sizeof(int));
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            while (top > 0 && a[st[top - 1]] >= a[i]) --top;
            prev[i] = (top == 0 ? 0 : st[top - 1]);
            st[top++] = i;
        }
        top = 0;
        for (int i = n; i >= 1; --i) {
            while (top > 0 && a[st[top - 1]] > a[i]) --top;
            next[i] = (top == 0 ? (n + 1) : st[top - 1]);
            st[top++] = i;
        }

        // 生成 (value, count) 对
        Pair *pairs = (Pair *)malloc(((size_t)n + 5u) * sizeof(Pair));
        for (int i = 1; i <= n; ++i) {
            ull L = (ull)(i - prev[i]);
            ull R = (ull)(next[i] - i);
            pairs[i - 1].v = a[i];
            pairs[i - 1].c = L * R;
        }

        qsort(pairs, (size_t)n, sizeof(Pair), cmp_pair);

        // 压缩相同值
        int k = 0;
        Pair *uniq = (Pair *)malloc(((size_t)n + 5u) * sizeof(Pair));
        for (int i = 0; i < n; ) {
            ll v = pairs[i].v; u128 csum = 0;
            while (i < n && pairs[i].v == v) { csum += (u128)pairs[i].c; ++i; }
            uniq[k].v = v; // csum 可能 >2^64，但总子数组数 <= 5e10，仍可放进 64bit
            // 但为了稳妥，仍按 64 位存储（安全范围内）
            unsigned long long cc = (unsigned long long)csum; // csum <= n*(n+1)/2 <= 5e10
            uniq[k].c = cc;
            ++k;
        }

        // 前缀和（用于后缀查询）
        unsigned long long *prefC = (unsigned long long *)malloc(((size_t)k + 5u) * sizeof(unsigned long long));
        u128 *prefVC = (u128 *)malloc(((size_t)k + 5u) * sizeof(u128));
        u128 sVC = 0; unsigned long long sC = 0;
        for (int i = 0; i < k; ++i) {
            sC += uniq[i].c;
            sVC += (u128)((i128)uniq[i].v) * (u128)uniq[i].c;
            prefC[i] = sC;
            prefVC[i] = sVC;
        }

        // 总子数组数
        unsigned long long Total = (unsigned long long)n * (unsigned long long)(n + 1) / 2ull;

        int m; scanf("%d", &m);
        printf("Case %d:\n", tc);
        for (int qi = 0; qi < m; ++qi) {
            long long e; scanf("%lld", &e);
            // 二分找第一个 v>e 的位置
            int lo = 0, hi = k;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (uniq[mid].v <= e) lo = mid + 1; else hi = mid;
            }
            if (lo == k) { puts("0"); continue; }
            // 后缀和
            unsigned long long S2 = prefC[k - 1] - (lo ? prefC[lo - 1] : 0ull);
            u128 S1 = prefVC[k - 1] - (lo ? prefVC[lo - 1] : (u128)0);
            // 分子：S1 - e*S2
            u128 Numer = S1 - (u128)((i128)e) * (u128)S2;
            if (Numer == 0) { puts("0"); continue; }
            // 若可整除，输出整数
            u128 mod = Numer % (u128)Total;
            if (mod == 0) {
                u128 A = Numer / (u128)Total;
                print_u128(A); putchar('\n');
            } else {
                unsigned long long r = (unsigned long long)mod; // mod < Total
                unsigned long long g = gcd_ull(Total, r);
                u128 A = Numer / (u128)g;
                unsigned long long B = Total / g;
                print_u128(A); putchar('/');
                // 打印 B（64 位）
                char buf[32]; int p = 0; unsigned long long Bb = B;
                if (Bb == 0) { putchar('0'); }
                else {
                    while (Bb) { buf[p++] = (char)('0' + (Bb % 10)); Bb /= 10; }
                    while (p--) putchar(buf[p]);
                }
                putchar('\n');
            }
        }

        free(a); free(prev); free(next); free(st); free(pairs); free(uniq); free(prefC); free(prefVC);
    }
    return 0;
}