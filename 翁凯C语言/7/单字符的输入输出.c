#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !���ַ����������
/*
	1.putchar
	  int putchar(int c);
	  ���׼���дһ���ַ�
	  ����д�˼����ַ���EOF��-1����ʾдʧ��
	2.getchar
	  int getchar(void);
	  �ӱ�׼�������һ���ַ�
	  ����������int��Ϊ�˷���EOF (-1��
	  Windows->Ctrl-Z
	  Unix��>Ctrl-D
	3.

*/

int main(void)
{
	int ch;

	while ((ch=getchar())!=EOF)
	{
		putchar(ch);
	}

	printf("EOF\n");
	
	return 0;
}