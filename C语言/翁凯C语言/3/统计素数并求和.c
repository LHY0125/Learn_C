#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int is_sushu(int x)     //判断一个数是否是素数
{
    if (x <= 1)
        return 0;
    for (int a = 2; a <= sqrt(x); a++)
    {
        if (x % a == 0)
        {
            return 0;
        }
    }
    return 1;
}

int num_sushuhe(int x, int y)   //计算区间[x,y]内素数的和
{
    int sum = 0;
    for (int e = x; e <= y; e++)
    {
        if (is_sushu(e))
        {
            sum += e;
        }
    }
    return sum;
}

int main()
{
    int m, n;
    printf("请输入两个正整数m和n:");
    scanf("%d %d", &m, &n);

    if (n > m)  // 确保m <= n
    {
        int temp = m;
        m = n;
        n = temp;
    }

    if (n < 1 || m < 1)
    {
        printf("输入错误，请重新输入！\n");
    }
    else
    {
        printf("素数列表: ");
        for (int x = n; x <= m; x++)
        {
            if (is_sushu(x))
            {
                printf("%d ", x);
            }
        }
        printf("\n素数和: %d\n", num_sushuhe(n, m));
    }
    return 0;
}
