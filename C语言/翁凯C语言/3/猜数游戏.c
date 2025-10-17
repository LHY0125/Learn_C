#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()  //自己输入数字，自己猜
{
    int a, b, c, d;
    printf("请输入一个设计的整数和设计轮数：");
    scanf("%d %d", &a, &b);
    while(c!=a)
    {
        c = 0;
        d = 1;
        d++;
        printf("请输入一个的整数：");
        scanf("%d", &c);
        if(c>a)
        {
            printf("大了！\n");
        }
        else if(c<a)
        {
            printf("小了！\n");
        }
        else
        {
            d++;
            if (d <= b)
            {
                printf("你只猜了%d次，就猜对了！\n", d);
            }
            else
            {
                printf("你一共猜了%d次，才猜对！\n", d);
            }
        }
    }
    return 0;
}