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
	4.strcpy
	  char * strcpy(char *restrict dst, const char *restrict src);
	  把src的字符串拷贝到dst
	  restrict表明src和dst不重叠(C99)
	  返回dst 为了能链起代码来
	  * 复制一个字符串
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