#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a,int b)	//���Լ��
{
	int gcd = a;
	if (a>b)
	{
		gcd = b;
	}
	for (;gcd>=1;gcd--)
	{
		if (a%gcd==0 && b%gcd==0)
		{
			return gcd;
			break;
		}
	}
}
int main()
{
	int a;
	int b;
    printf("����������������");
    scanf("%d %d", &a, &b);

	if (a<0 || b<0)
	{
		printf("����������������룡\n");
		return -1;
	}
	else
	{
		printf("%d��%d�����Լ���ǣ�%d\n", a, b, gcd(a, b));
	}
	return 0;
}