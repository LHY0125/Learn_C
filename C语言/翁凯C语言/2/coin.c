#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	int n=0;
	int one,two,five;

	printf("������Ǯ�����");
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
					printf("%dԪ��Ǯ������%d��1�ǡ�%d��2�Ǻ�%d��5�ǻ�\n", x, one, two, five);
				}
			}
		}
	}
	printf("һ����%d�Ŀ�����", n);

	return 0;
}
