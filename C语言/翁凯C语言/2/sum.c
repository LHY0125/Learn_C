#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int x;
	double f=0.0;		//f������������С������double��ʾ

	printf("���������֣�");
	scanf("%d", &n);

	for (x=1 ; x<=n; x++)
	{
		f = f+(1.0/x);	//1������������С������1.0��ʾС��������
	}
	
	printf("f(%d)=%f\n", n, f);	//f������������С������%f��ʾ������

	return 0;
}
