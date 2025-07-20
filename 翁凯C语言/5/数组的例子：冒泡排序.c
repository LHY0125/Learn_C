#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !判断能被已知的且为素数的数整除（构造素数表）
/*  
    欲构造n以内的素数表
    1.令x=2
    2.将2x、3x、4x直至ax<n的数标记为非素数
    3.令x为下一个没有被标记为非素数的数，重复步骤2；直到所有的数都已经尝试完毕
*/

// !数组的赋值
/*
    数组赋值有两种方式
    1.用赋值号直接赋值
    2.用循环赋值
    例如：
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10];
    for(int i=0;i<10;i++)
    {
        b[i]=a[i];
    }
    数组不能用来赋另外一个数组的值
*/

int main()
{
    int a[10], i, j, temp;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}