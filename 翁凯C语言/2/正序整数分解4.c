#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int num_weishu(int num) //�ж�����λ��
{
	int n = 0;
	num = abs(num);
	if (num == 0)
	{
		return 1;
	}          
	while (num > 0)
	{
		num /= 10;
		n++;
	}
	return n;
}

int main()
{
	int x;
	int a=0;
	int b=0;
	int m=0;
    printf("������һ��������");
    scanf("%d", &x);

	a = num_weishu(x);
	b = (int)(pow(10,a-1)+0.1);		//pow�����Ǵη�����ĺ�����,+0.1��Ϊ�˱��⸡�������
	printf("������ֵ�λ����%d��\n", a);

	if(a>9)
	{
		printf("�������֧��λ����\n");
		return -1;
	}
	else
	{
		
		if (x<0) 	// ������
		{
			printf("-");
		}	
		while (b>0)
		{
			m = x/b;
			printf("%d", m);
			if (b>9)
			{
				printf(" ");
			}
			x = x%b;
			b = b/10;
		} 
		printf("\n");
	}

	return 0;
}