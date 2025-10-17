#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num_weishu(int num) //判断数字位数
{
	int n = 0;
	num = abs(num);
	if (num==0)
	{
		return 1;
	}          
	while (num>0)
	{
		num /= 10;
		n++;
	}
	return n;
}

int main()
{
	int x;
	int m=0;
    printf("请输入一个整数：");
    scanf("%d", &x);
	int a = num_weishu(x);

	if(a>9)
	{
		printf("超过最大支持位数！\n");
		return -1;
	}
	else
	{
		while (a>0)
		{
			m = x/a;
			printf("%d", m);
			x = x%a;
			a = a/10;
			if (a>1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
