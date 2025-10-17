#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a=1;
	int b=n;

	for(n=n;n>1;n-- )
	{
		a=a*n;
	}
	printf("%d!=%d\n", b, a);

	return 0;
}