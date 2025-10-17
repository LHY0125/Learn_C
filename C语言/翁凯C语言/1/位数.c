#include <stdio.h>

int main()
{  
	int x;
	int n=0;
	
	scanf("%d", &x);
	
	n++;
	x=x/10;
	while(x>10)
	{
		n++;
		x=x/10;
	}
	printf("%d\n",n);
	return 0;
}