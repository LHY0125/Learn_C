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

int main(int argc, char const *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("%d:%s\n", i, argv[i]);
	}

	return 0;
}