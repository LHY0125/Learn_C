#include <stdio.h>
#include <stdlib.h>

int num_weishu(int num) {
    int n = 0;
    num = abs(num);
    if (num == 0) return 1;
    while (num > 0) {
        num /= 10;
        n++;
    }
    return n;
}

int main() 
{
    int x, sign = 1;
    printf("请输入一个整数：");
    scanf("%d", &x);

    if (x < 0) 	// 处理负数符号
	{
        sign = -1;
        x = -x; // 转换为正数处理
    }

    int a = num_weishu(x);
    if (a > 9)
	{
        printf("超过最大支持位数！\n");
        return -1;
    } 
	else
	{
        int b=1;
        while (a>0) 
		{
            int m = x/a;	// 第一个数字应用符号
            if (b) 
			{
                printf("%d", sign*m);
                b = 0;
            } 
			else 
			{
                printf("%d", m);
            }
            x %= a;
            a /= 10;
            if (a > 0) printf(" "); 	//后续数字后加空格
        }
        printf("\n");
    }

    return 0;
}