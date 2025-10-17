#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int num_sum(int a, int b)   // 函数定义
{
    int sum = 0;
    for (int i = a; i <= b;i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int a, b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    printf("%d和%d之间的所有数的和：sum = %d\n", a, b, num_sum(a, b));

    return 0;
}