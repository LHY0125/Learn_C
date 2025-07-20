#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int n=9;
    printf("请输入一个正整数n：");
    scanf("%d", &n);

    if (n < 1 || n > 9)
    {
        printf("输入错误，请重新输入！\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("%d*%d=%d  ", i, j, i * j);
                if (i == j)
                {
                    printf("\n");
                }
            }
        }
    }
    return 0;
}