#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !字符串的输入输出
/*
	1.字符串赋值？
	  char *t =“title”
	  char *s;
	  s=t;
	  并没有产生新的字符串，只是让指针s指向了t所指的字符串,对s的任何操作就是对t做的
	2.字符串输入输出
	  char string[8];
	  scanf("%s",string);
	  printf("%s",string);
	  scanf读入一个单词(到空格、tab或回车为止)
	  scanf是不安全的，因为不知道要读入的内容的长度
	3.安全的输入
	  char string[8];
	  scanf("%7s", string);
	  在%和s之间的数字表示最多允许读入的字符的数量，这个数字应该比数组的大小小一
	  下一次scanf从哪里开始?
	4.常见错误
	  char *string;
	  scanf("%s", string);
	  以为char*是字符串类型，定义了一个字符串类型的
	  变量string就可以直接使用了
	  由于没有对string初始化为0，所以不一定每次运行都出错
	5.空字符串
	  char buffer[100]="";
	  这是一个空的字符串，buffer[0]=='\0'
	  char buffer[]="";
	  这个数组的长度只有1！

*/

int main(void)
{
	char word1[8];
	char word2[8];
	scanf("%7s", word1);	// 读入一个单词
	scanf("%7s", word2);	//%7s表示最多读入7个字符，最后一个字符是\0,防止越界
	printf("%s##%s##\n", word1, word2);

	return 0;
}