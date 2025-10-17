#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int a[10]={0};
    int count=0;
    while(1)
    {
        int b;
        printf("请输入一个数字：");
        scanf("%d",&b);

        if(b==-1)
        {
            break;
        }

        if (b<=-1 || b>=10)
        {
            printf("输入错误,请重新输入\n");
            continue;
        }

        if (count<10)
        {
            printf("数组已满\n");
            break;
        }
        
        a[b]++;
        count++;
    }

    for (int i = 0; i < 10; i++) 
    {
        printf("%d: %d\n", i, a[i]);
    }

    return 0;
}