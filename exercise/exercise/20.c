// 非递归层序遍历（BFS）（给出每个结点的左右孩子编号，根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示无孩子）。
// 输出：层序遍历序列，每个数字后均输出一个空格。

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) return 0;

    int *L = (int *)malloc((n + 1) * sizeof(int));
    int *R = (int *)malloc((n + 1) * sizeof(int));
    if (!L || !R) return 0;

    for (int i = 1; i <= n; ++i) {
        int l, r;
        if (scanf("%d %d", &l, &r) != 2) {
            free(L); free(R);
            return 0;
        }
        L[i] = l; R[i] = r;
    }

    // 队列 BFS，从根 1 开始，左到右按层输出
    int *q = (int *)malloc((n + 1) * sizeof(int));
    if (!q) { free(L); free(R); return 0; }
    int head = 0, tail = 0;

    q[tail++] = 1; // 根节点为 1
    while (head < tail) {
        int u = q[head++];
        if (u == 0) continue;
        printf("%d ", u);
        if (L[u]) q[tail++] = L[u];
        if (R[u]) q[tail++] = R[u];
    }

    free(q);
    free(L); free(R);
    return 0;
}