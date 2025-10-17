#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a,int b)	//最大公约数
{
	int gcd = a;
	if (a>b)
	{
		gcd = b;
	}
	for (;gcd>=1;gcd--)
	{
		if (a%gcd==0 && b%gcd==0)
		{
			return gcd;
			break;
		}
	}
}
int main()
{
	int a;
	int b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);

	if (a<0 || b<0)
	{
		printf("输入错误，请重新输入！\n");
		return -1;
	}
	else
	{
		printf("%d和%d的最大公约数是：%d\n", a, b, gcd(a, b));
	}
	return 0;
}