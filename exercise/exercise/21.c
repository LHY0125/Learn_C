// 前序线索二叉树构建（根为1）
// 输入：n，随后 n 行，每行两个整数 l、r（0 表示无孩子）。
// 输出：n 行，每行四个整数：lchild(i) ltag(i) rchild(i) rtag(i)
// 规则：
//  - 若有左儿子：ltag(i)=0，lchild(i) 为左儿子编号；否则 ltag(i)=1，lchild(i) 为前序前驱，无前驱为 -2。
//  - 若有右儿子：rtag(i)=0，rchild(i) 为右儿子编号；否则 rtag(i)=1，rchild(i) 为前序后继，无后继为 -1。

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

    // 迭代前序遍历，生成访问序列 order
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int *order = (int *)malloc(n * sizeof(int));
    if (!stack || !order) { free(L); free(R); return 0; }
    int top = 0, k = 0;

    stack[top++] = 1; // 根为 1
    while (top) {
        int u = stack[--top];
        if (u == 0) continue;
        order[k++] = u;
        if (R[u]) stack[top++] = R[u];
        if (L[u]) stack[top++] = L[u];
    }

    // 位置映射：pos[node] = 在前序序列中的索引
    int *pos = (int *)malloc((n + 1) * sizeof(int));
    if (!pos) { free(stack); free(order); free(L); free(R); return 0; }
    for (int i = 1; i <= n; ++i) pos[i] = -1;
    for (int i = 0; i < k; ++i) pos[order[i]] = i;

    // 输出域与标记域
    int *outL = (int *)malloc((n + 1) * sizeof(int));
    int *ltag = (int *)malloc((n + 1) * sizeof(int));
    int *outR = (int *)malloc((n + 1) * sizeof(int));
    int *rtag = (int *)malloc((n + 1) * sizeof(int));
    if (!outL || !ltag || !outR || !rtag) {
        free(pos); free(stack); free(order); free(L); free(R);
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (L[i]) { // 有左儿子
            ltag[i] = 0;
            outL[i] = L[i];
        } else {    // 无左儿子，线索到前序前驱
            ltag[i] = 1;
            if (pos[i] > 0) outL[i] = order[pos[i] - 1];
            else outL[i] = -2; // 无前驱
        }

        if (R[i]) { // 有右儿子
            rtag[i] = 0;
            outR[i] = R[i];
        } else {    // 无右儿子，线索到前序后继
            rtag[i] = 1;
            if (pos[i] >= 0 && pos[i] < k - 1) outR[i] = order[pos[i] + 1];
            else outR[i] = -1; // 无后继
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d %d\n", outL[i], ltag[i], outR[i], rtag[i]);
    }

    free(outL); free(ltag); free(outR); free(rtag);
    free(pos); free(stack); free(order);
    free(L); free(R);
    return 0;
}