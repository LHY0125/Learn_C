#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !字符串函数string.h
/*
	1.string.h
	  strlen、strcmp、strcpy、strcat、strchr、strstr
	2.strlen
	  size_t strlen(const char *s);
	  返回s的字符串长度（不包括结尾的0)
	3.strcmp
	  int strcmp(const char *s1, const char *s2); 比较两个字符串，返回:
	  0:s1==S2
	  1:s1>s2
	  -1:s1<s2
*/

int my_strcmp(const char *s1, const char *s2)
{
	int idx = 0;
	while (s1[idx]!='\0' && s1[idx] == s2[idx])
	{
		idx++;
	}
	return s1[idx] - s2[idx];
}

int main(void)
{
	/* strcmp */
	char s1[] = "abc";
	char s2[] = "abc";
	printf("strcmp=%d\n", strcmp(s1, s2));

	char s3[] = "abc";
	char s4[] = "bbc";
	printf("strcmp=%d\n", strcmp(s3, s4));

	char s5[] = "abc";
	char s6[] = "Abc";
	printf("strcmp=%d\n", strcmp(s5, s6));

	return 0;
}