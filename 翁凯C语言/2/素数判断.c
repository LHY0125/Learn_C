#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	printf("输入数字：");
	scanf("%d", &n);

	int a;
	int b=1;

	for(a=2;a<n;a++)
	{
		if(n%a==0)
		{
			b=0;
			break;
		}
	}
	if(b==1)
	{
		printf("%d是素数", n);
	}
	else if (b==0)
	{
		printf("%d不是素数", n);
	}

	return 0;
}