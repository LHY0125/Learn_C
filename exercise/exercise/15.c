// 二叉树中序遍历（给出每个结点的左右孩子编号，根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示空）。
// 输出：中序遍历序列，每个数字后均输出一个空格。

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

    // 迭代式中序遍历：一路向左压栈，弹栈访问，再转向右子树
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = 0;
    int cur = 1; // 根节点编号为 1

    while (cur || top) {
        while (cur) { // 沿左链入栈
            stack[top++] = cur;
            cur = L[cur];
        }
        int u = stack[--top];
        printf("%d ", u);
        cur = R[u];
    }

    free(stack);
    free(L); free(R);
    return 0;
}