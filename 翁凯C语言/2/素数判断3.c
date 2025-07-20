#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// !素数判断的简化版本
int sushu(int x)
{
	int ret = 1;

	if (x <= 1) 
	{
		ret = 0;
	}

	int i;
	if (x == 2 || (x % 2 == 0 && x != 2))	// 排除偶数
	{
		ret = 0;
	}
	for (i = 3; i < (int)sqrt(x)+1; i += 2)
	{
		if (x % i == 0)
		{
			ret = 0;
			break;
		}
	}
	
	return ret;
}

int main()
{
	int x;
	printf("输入数字：");
	scanf("%d", &x);

	if (sushu(x))
	{
		printf("%d是素数\n", x);
	}
	else
	{
		printf("%d不是素数\n", x);
	}

	return 0;
}