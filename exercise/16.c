// 二叉树后序遍历（给出每个结点的左右孩子编号，根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示空）。
// 输出：后序遍历序列，每个数字后均输出一个空格。

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

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

    // 迭代式后序遍历：使用两个栈
    // 栈1：根右左；栈2：左右根（输出时弹出栈2）
    int *s1 = (int *)malloc((n + 1) * sizeof(int));
    int *s2 = (int *)malloc((n + 1) * sizeof(int));
    int t1 = 0, t2 = 0;

    s1[t1++] = 1; // 根节点为 1
    while (t1) {
        int u = s1[--t1];
        if (u == 0) continue;
        s2[t2++] = u;
        // 先压左，再压右，使栈2形成 左右根 的逆序
        if (L[u]) s1[t1++] = L[u];
        if (R[u]) s1[t1++] = R[u];
    }

    while (t2) {
        int u = s2[--t2];
        printf("%d ", u);
    }

    free(s1); free(s2);
    free(L); free(R);
    return 0;
}