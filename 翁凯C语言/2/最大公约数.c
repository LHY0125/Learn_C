#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int num_small(int a,int b)
{
	int n = a;
	if (a>b)
	{
		n = b;
	}
	return n;
}

int main()
{
	int gcd=0;
	int a;
	int b;
	int n;
    printf("����������������");
    scanf("%d %d", &a, &b);

	if (a<0 || b<0)
	{
		printf("����������������룡\n");
		return -1;
	}
	else
	{
		n = num_small(a,b);

		for (gcd=n;gcd>=1;gcd--)
		{
			if (a%gcd==0 && b%gcd==0)
			{
				printf("���Լ���ǣ�%d\n", gcd);
				break;
			}
			
		}
	}
	return 0;
}