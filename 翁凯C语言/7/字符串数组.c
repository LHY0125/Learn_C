#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !�ַ�������
/*
	1.�ַ�������
	  char* *a
		a��һ��ָ�룬ָ����һ��ָ�룬�Ǹ�ָ��ָ��һ���ַ�(����
	  char a[][]
	2.�������
	  int main(int argc, char const *argv[])
	  argv[0]�������
	  ��ʹ��Unix�ķ�������ʱ����ӳ�������ӵ�����
*/

int main(void)
{
	char a[][10] = {"Hello",
					"World",
					"C",
					"Language"};
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", a[i]);
	}
	printf("\n");

	/* a[0] --> char* */
	char *b[] = {"Hello",
				 "World",
				 "C",
				 "Language"};
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", b[i]);
	}
	printf("\n");
}