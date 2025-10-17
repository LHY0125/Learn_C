#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
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
					printf("%d元的钱可以用%d个1角、%d个2角和%d个5角换\n", x, one, two, five);
					goto out;	//多层嵌套的循环的内层直接结束跳到最外层的out:
				}
			}
		}
	}
	out:

	return 0;
}
