#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int num_weishu(int num) //判断数字位数
{
	int n = 0;
	num = abs(num);
	if (num == 0)
	{
		return 1;
	}          
	while (num > 0)
	{
		num /= 10;
		n++;
	}
	return n;
}

int main()
{
	int x;
	int a=0;
	int b=0;
	int m=0;
    printf("请输入一个整数：");
    scanf("%d", &x);

	a = num_weishu(x);
	b = (int)(pow(10,a-1)+0.1);		//pow函数是次方运算的函数名,+0.1是为了避免浮点数误差
	printf("这个数字的位数是%d。\n", a);

	if(a>9)
	{
		printf("超过最大支持位数！\n");
		return -1;
	}
	else
	{
		
		if (x<0) 	// 处理负号
		{
			printf("-");
		}	
		while (b>0)
		{
			m = x/b;
			printf("%d", m);
			if (b>9)
			{
				printf(" ");
			}
			x = x%b;
			b = b/10;
		} 
		printf("\n");
	}

	return 0;
}