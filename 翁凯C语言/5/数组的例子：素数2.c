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
    int minnum,maxnum;
    printf("请输入一个数(即为最小和最大的区间)：");
    scanf(" %d %d", &minnum, &maxnum);

    int isprime[maxnum];
    int i, x;

    if (maxnum<=0)
    {
        printf("输入错误！");
        return 0;
    }

    for (i = 0; i < maxnum; i++)// 令isprime[i]=1，采用循环赋值，默认所有的数都是素数，标记为1
    {
        isprime[i] = 1;
    }

    for (x = 2; x < maxnum; x++)
    {
        if (isprime[x]==1)      // isprime[x]判断是否为素数
        {
            /* x的倍数不是素数 */
            for (i = 2; i*x < maxnum; i++)
            {
                isprime[i*x] = 0;
            }
        }
    }

    for (x = 2; x < minnum;x++) // 将比minnum小的数标记为非素数，即不打印
    {
        isprime[x] = 0;
    }

    for (x = 2; x < maxnum; x++)// 打印素数
    {
        if (isprime[x] == 1)
        {
            printf("%d是素数\n", x);
        }
    }

    return 0;
}