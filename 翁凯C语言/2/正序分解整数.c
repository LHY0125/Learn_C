#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	int a=0;
	int n=0;
	int m=0;
	printf("ÇëÊäÈëÊý×Ö£º");
	scanf("%d", &x);

	do{
		a = x%10;
		n = n*10+a;
		x = x/10;
	} while (x>0);
	
	do{
		m = n%10;
		printf("%d", m);
		if (n>=10)
		{
			printf(" ");
		}
		n = n/10;
	} while (n>0);
	printf("\n");

	return 0;
}
