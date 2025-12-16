#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int N;
        scanf("%d", &N);
        
        int a[10000];
        
        // 读取序列
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
        }
        
        // 找最大值和最小值的位置
        int max_pos = 0, min_pos = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] > a[max_pos])
            {
                max_pos = i;
            }
            if (a[i] < a[min_pos])
            {
                min_pos = i;
            }
        }
        
        // 交换最大值和最小值
        int temp = a[max_pos];
        a[max_pos] = a[min_pos];
        a[min_pos] = temp;
        
        // 输出结果
        for (int i = 0; i < N; i++)
        {
            printf("%d", a[i]);
            if (i < N - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}