// 非递归中序遍历。给出每个结点的左右孩子编号，根为 1。
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示无孩子）。
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

    // 非递归中序遍历（栈）
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = 0;
    int cur = 1; // 根结点为 1

    while (cur || top) {
        while (cur) {               // 沿左链压栈
            stack[top++] = cur;
            cur = L[cur];
        }
        int u = stack[--top];       // 访问栈顶
        printf("%d ", u);
        cur = R[u];                 // 转向右子树
    }

    free(stack);
    free(L); free(R);
    return 0;
}