#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int x;
	double f=0.0;		//f不是整数，是小数，用double表示

	printf("请输入数字：");
	scanf("%d", &n);

	for (x=1 ; x<=n; x++)
	{
		f = f+(1.0/x);	//1是整数，不是小数，用1.0表示小数的运算
	}
	
	printf("f(%d)=%f\n", n, f);	//f不是整数，是小数，用%f表示浮点数

	return 0;
}
