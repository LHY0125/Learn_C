#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int x=0;
	printf("ÊäÈëÊı×Ö£º");
	scanf("%d", &x);

	for(n=2;n<=x;n++)
	{
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
			printf("%d\n", n);
		}
	}

	return 0;
}