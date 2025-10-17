#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a,int b)
{
	int c;
	while(c>0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
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