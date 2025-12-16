// 非递归先序遍历（给出每个结点的左右孩子编号，根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示无孩子）。
// 输出：先序遍历序列，每个数字后均输出一个空格。

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

    // 迭代版先序遍历：使用一个栈，根开始；弹出访问当前结点，先压右再压左
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = 0;
    stack[top++] = 1; // 根节点为 1

    while (top) {
        int u = stack[--top];
        if (u == 0) continue;
        printf("%d ", u);
        if (R[u]) stack[top++] = R[u];
        if (L[u]) stack[top++] = L[u];
    }

    free(stack);
    free(L); free(R);
    return 0;
}