#include <stdio.h>
#include <stdlib.h>

// 目标：在允许使用容量为 c 的栈缓冲的前提下，
// 将输入序列（商店从上到下）重排为字典序最小的最终堆叠（从下到上）。
// 操作等价于：依次读取输入；每次要么将下一个元素压入栈（若未满），要么从栈顶弹出到输出；
// 栈容量不超过 c；输出顺序即为最终堆叠的自下而上的编号。

int main(void)
{
    int n, c;
    if (scanf("%d %d", &n, &c) != 2)
        return 0;
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    // 栈缓冲（手上带着的箱子），存储值
    int *stk = (int *)malloc(sizeof(int) * n);
    int len = 0; // 当前栈大小

    // 单调队列（维护接下来可压入窗口中的最小值及其位置）
    int *dq_val = (int *)malloc(sizeof(int) * n);
    int *dq_idx = (int *)malloc(sizeof(int) * n);
    int dq_head = 0, dq_tail = 0; // [head, tail) 有效

    int i = 0;    // 下一个待读取的输入位置
    int j = 0;    // 已加入单调队列的输入位置（下一个待加入的位置）
    int out_cnt = 0;

    while (out_cnt < n)
    {
        // 计算当前还能压入的最大数量 R（窗口大小）
        int R = c - len;
        if (R < 0)
            R = 0;

        // 扩充单调队列，使其覆盖 [i, min(i+R-1, n-1)]
        while (j < n && j < i + R)
        {
            int v = a[j];
            while (dq_tail > dq_head && dq_val[dq_tail - 1] > v)
                --dq_tail;
            dq_val[dq_tail] = v;
            dq_idx[dq_tail] = j;
            ++dq_tail;
            ++j;
        }

        // 若栈非空，比较栈顶与窗口内最小值，决定弹出还是继续压入到最小值位置
        if (len > 0)
        {
            int top = stk[len - 1];
            int hasUpcoming = (dq_tail > dq_head);
            int minUpcoming = hasUpcoming ? dq_val[dq_head] : 2147483647; // INF
            if (!hasUpcoming || top <= minUpcoming)
            {
                // 栈顶不大于可达窗口中的最小值（或无可压入项），弹出栈顶到输出
                printf("%d", top);
                ++out_cnt;
                if (out_cnt < n)
                    putchar(' ');
                --len;
                continue;
            }
        }

        // 否则（栈为空或栈顶较大且尚有可压入项），把队列窗口的最小值所在位置的元素压入到栈顶，然后立即弹出
        if (dq_tail > dq_head)
        {
            int target_pos = dq_idx[dq_head];
            // 逐个压入直到到达 target_pos
            while (i <= target_pos)
            {
                stk[len++] = a[i++];
            }
            // 清理队列中过期项（索引 < i 的）
            while (dq_tail > dq_head && dq_idx[dq_head] < i)
                ++dq_head;

            // 弹出刚压入的最小值
            int val = stk[len - 1];
            printf("%d", val);
            ++out_cnt;
            if (out_cnt < n)
                putchar(' ');
            --len;
        }
        else
        {
            // 没有可压入项，但仍需输出 -> 只能弹出栈顶
            if (len > 0)
            {
                int val = stk[len - 1];
                printf("%d", val);
                ++out_cnt;
                if (out_cnt < n)
                    putchar(' ');
                --len;
            }
            else
            {
                // 理论上不会到这里（既无可压入项又无栈元素），为安全直接中断
                break;
            }
        }
    }

    putchar('\n');

    free(a);
    free(stk);
    free(dq_val);
    free(dq_idx);
    return 0;
}