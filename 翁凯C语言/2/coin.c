#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	int n=0;
	int one,two,five;

	printf("请输入钱的数额：");
	scanf("%d", &x);

	for(one=0;one<=x*10;one++)
	{
		for(two=0;two<=x*5;two++)
		{
			for(five=0;five<=x*2;five++)
			{
				if(one*1 + two*2 + five*5 == x*10)                
				{
					n +=1;
					printf("%d元的钱可以用%d个1角、%d个2角和%d个5角换\n", x, one, two, five);
				}
			}
		}
	}
	printf("一共有%d的可能性", n);

	return 0;
}
