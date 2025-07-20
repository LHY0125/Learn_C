#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !�ַ�������string.h
/*
	1.string.h
	  strlen��strcmp��strcpy��strcat��strchr��strstr
	2.strlen
	  size_t strlen(const char *s);
	  ����s���ַ������ȣ���������β��0)
	3.strcmp
	  int strcmp(const char *s1, const char *s2); �Ƚ������ַ���������:
	  0:s1==S2
	  1:s1>s2
	  -1:s1<s2
	4.strcpy
	  char * strcpy(char *restrict dst, const char *restrict src);
	  ��src���ַ���������dst
	  restrict����src��dst���ص�(C99)
	  ����dst Ϊ�������������
	  * ����һ���ַ���
	  * char *dst =(char*)malloc(strlen(src)+1);
	  * strcpy(dst, src);
	5.�ַ��������ַ�
	  char*strchr(const char *s, int c);
	  char*strrchr(const char *s, int c);
	  ����NULL��ʾû���ҵ�
	  ���Ѱ�ҵ�2��?
*/

int main(void)
{
	char s[]="hello";
	char *p1 = strchr( s, 'l' );
	printf("%s\n", p1);
	p1 = strchr(p1+1, 'l' );  	// !�ҵ�p1����һ��
	printf("%s\n", p1);

	char *p2 = strrchr( s, 'l' );
	printf("%s\n", p2);

	char *t = (char *)malloc(strlen(p1)+1);
	printf("%s\n", t);
	free(t);

	return 0;
}