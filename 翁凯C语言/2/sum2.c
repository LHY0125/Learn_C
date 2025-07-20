#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int m;
	int x;
	double f=0.0;		//f不是整数，是小数，用double表示

	printf("请输入数字：");
	scanf("%d", &n);

	for (x=1 ; x<=n; x++)
	{
		m = 1;
		if (x%2==0)
		{
			m = -1;
		}
		f = f+(1.0/x)*m;
	}
	
	printf("f(%d)=%f\n", n, f);	//f不是整数，是小数，用%f表示浮点数

	return 0;
}
