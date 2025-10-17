#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int power(int a, int x)	//a��x�η�����
{	
	if (x < 0)
	{
		printf("����������������룡\n");
		return -1;
	}
	else
	{
		int sum = 1;
		for (int i = 0; i < x; i++)
		{
			sum *= a;
		}
		return sum;
	}
}

int main()
{
	int n;
	printf("������һ��������n��3 �� n �� 7����");
	scanf("%d", &n);
	
	if (n < 3 || n > 7)
	{
		printf("����������������룡\n");
	}
	else
	{
		int lower = power(10, n - 1);	//nλ������Сֵ
		int upper = power(10, n) - 1;	//nλ�������ֵ

		for (int num = lower; num <= upper;num++)	//��С��Χ������������
		{
			int sum=0;
			int m = num;
			while(m>0)
			{
				int a = m % 10;
				sum += power(a,n);
				m /= 10;
			}
			if (num==sum)
			{
				printf("%d\n", sum);
			}
		}
	}

	return 0;
}