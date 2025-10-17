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
	3.
*/

int my_strlen(const char *s)
{
	int idx = 0;
	while (s[idx]!='\0')
	{
		idx++;
	}
	return idx;
}

int main(void)
{
	/* strlen */
	char line[] = "Hello";
	printf("strlen=%lu\n", strlen(line));
	printf("my_strlen=%d\n", my_strlen(line));
	printf("sizeof=%lu\n", sizeof(line));

	return 0;
}