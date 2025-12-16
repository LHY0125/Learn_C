// 二叉树先序遍历（给出每个结点的左右孩子编号）
// 输入：n，随后 n 行，每行两个整数 l、r 表示结点 i 的左右孩子编号（0 表示空）
// 根节点固定为 1。输出：先序遍历序列（每个数字后均有一个空格）。

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

    // 迭代版先序遍历，避免最坏情况下递归栈溢出（n 可达 1e5）
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = 0;
    stack[top++] = 1; // 根节点编号为 1

    while (top) {
        int u = stack[--top];
        if (u == 0) continue;
        printf("%d ", u);
        // 先压右再压左，保证左子树先被访问
        if (R[u]) stack[top++] = R[u];
        if (L[u]) stack[top++] = L[u];
    }

    free(stack);
    free(L); free(R);
    return 0;
}