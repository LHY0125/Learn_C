#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int n;
	int l;
	printf("������һ����������");
	scanf("%d", &n);
	printf("һ���м���������");
	scanf("%d", &l);

	if (n<=0)
	{
		printf("�����������������!\n");
	}
	else
	{

		int i, j, k;
		int m = 0;
		i = n;
		while(i<=n+3)
		{
			j = n;
			while(j<=n+3)
			{
				k = n;
				while(k<=n+3)
				{
					if (i!=j && j!=k && i!=k)
					{
						m++;
						printf("%d%d%d", i, j, k);
						if (m==l)
						{
							printf("\n");
							m = 0;
						}
						else
						{
							printf(" ");
						}
						
					}
					k++;
				}
				j++;
			}
			i++;
		}	

	}
	return 0;
}