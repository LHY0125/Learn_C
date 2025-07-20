#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a=1;
	int b=1;

	while(b<=n)
	{
		a=a*b;
		b=b+1;
	}
	printf("n!=%d\n", a);

	return 0;
}