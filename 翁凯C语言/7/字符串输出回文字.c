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

int main()
{
	char str[100];
	printf("������һ���ַ�����");
	scanf("%s", str);

	int len=strlen(str);	// !strlen()���������ַ����ĳ��ȣ�������'\0'�ַ�
	int is_huiwenzi = 1;

	for (int i = 0; i < len / 2;i++)
	{
		if (str[i]!=str[len-i-1])
		{
			is_huiwenzi = 0;
		}
	}
	if (is_huiwenzi)
	{
		printf("�ǻ�����\n");
	}
	else
	{
		printf("���ǻ�����\n");
	}

	return 0;
}