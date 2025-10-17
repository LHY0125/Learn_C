#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int num_small(int a,int b)
{
	int n = a;
	if (a>b)
	{
		n = b;
	}
	return n;
}

int main()
{
	int gcd=0;
	int a;
	int b;
	int n;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);

	if (a<0 || b<0)
	{
		printf("输入错误，请重新输入！\n");
		return -1;
	}
	else
	{
		n = num_small(a,b);

		for (gcd=n;gcd>=1;gcd--)
		{
			if (a%gcd==0 && b%gcd==0)
			{
				printf("最大公约数是：%d\n", gcd);
				break;
			}
			
		}
	}
	return 0;
}