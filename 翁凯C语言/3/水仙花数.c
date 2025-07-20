#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int power(int a, int x)	//a的x次方运算
{	
	if (x < 0)
	{
		printf("输入错误，请重新输入！\n");
		return -1;
	}
	else
	{
		int sum = 1;
		for (int i = 0; i < x; i++)
		{
			sum *= a;
		}
		return sum;
	}
}

int main()
{
	int n;
	printf("请输入一个正整数n（3 ≤ n ≤ 7）：");
	scanf("%d", &n);
	
	if (n < 3 || n > 7)
	{
		printf("输入错误，请重新输入！\n");
	}
	else
	{
		int lower = power(10, n - 1);	//n位数的最小值
		int upper = power(10, n) - 1;	//n位数的最大值

		for (int num = lower; num <= upper;num++)	//缩小范围，减少运算量
		{
			int sum=0;
			int m = num;
			while(m>0)
			{
				int a = m % 10;
				sum += power(a,n);
				m /= 10;
			}
			if (num==sum)
			{
				printf("%d\n", sum);
			}
		}
	}

	return 0;
}