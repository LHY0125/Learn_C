#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// !�����жϵļ򻯰汾
int sushu(int x)
{
	int ret = 1;

	if (x <= 1) 
	{
		ret = 0;
	}

	int i;
	if (x == 2 || (x % 2 == 0 && x != 2))	// �ų�ż��
	{
		ret = 0;
	}
	for (i = 3; i < (int)sqrt(x)+1; i += 2)
	{
		if (x % i == 0)
		{
			ret = 0;
			break;
		}
	}
	
	return ret;
}

int main()
{
	int x;
	printf("�������֣�");
	scanf("%d", &x);

	if (sushu(x))
	{
		printf("%d������\n", x);
	}
	else
	{
		printf("%d��������\n", x);
	}

	return 0;
}