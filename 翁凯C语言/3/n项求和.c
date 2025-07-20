#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int N;
    printf("请输入项数N: ");
    scanf("%d", &N);
    double a = 2.0, b = 1.0, sum = 0.0;
    
    for (int i = 0; i < N; i++)
    {
        sum += a / b;
        double next_a = a + b;  // 计算下一项的分子
        double next_b = a;      // 计算下一项的分母
        a = next_a;             // 更新分子
        b = next_b;             // 更新分母
    }
    printf("%.2f\n", sum);

    return 0;
}