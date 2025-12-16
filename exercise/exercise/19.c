// 非递归后序遍历（给出每个结点的左右孩子编号，根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示无孩子）。
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

    // 单栈 + 最近访问标记 实现后序遍历
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = 0;
    int cur = 1;        // 根结点编号为 1
    int prev = 0;       // 最近一次输出的结点编号

    while (cur || top) {
        if (cur) {
            stack[top++] = cur;
            cur = L[cur];   // 沿左链压栈
        } else {
            int u = stack[top - 1];
            // 若右子树存在且未被处理，则转向右子树
            if (R[u] && prev != R[u]) {
                cur = R[u];
            } else {
                // 右子树为空或已处理，弹栈并输出该结点
                --top;
                printf("%d ", u);
                prev = u;
            }
        }
    }

    free(stack);
    free(L); free(R);
    return 0;
}