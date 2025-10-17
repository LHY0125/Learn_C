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
*/

int my_strcpy(char *restrict dst, const char *restrict src)
{
	int idx = 0;
	while (src[idx]!='\0')
	{
		dst[idx]=src[idx];
		idx++;
	}
	dst[idx]='\0';
	return dst;
}

int main(void)
{
	/* strcpy */
	

	return 0;
}