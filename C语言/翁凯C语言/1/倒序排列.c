#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	scanf("%d", &x);

	int number;
	int renum=0;

	while(x>0)
	{
		number = x%10;
		printf("%d", number);
		renum = renum*10+number;
		printf("x=%d, number=%d,renum=%d\n", x, number, renum);
		x/=10;
	}
	printf("%d", renum);

	return 0;
}