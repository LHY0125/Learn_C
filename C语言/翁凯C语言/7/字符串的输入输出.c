#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !�ַ������������
/*
	1.�ַ�����ֵ��
	  char *t =��title��
	  char *s;
	  s=t;
	  ��û�в����µ��ַ�����ֻ����ָ��sָ����t��ָ���ַ���,��s���κβ������Ƕ�t����
	2.�ַ����������
	  char string[8];
	  scanf("%s",string);
	  printf("%s",string);
	  scanf����һ������(���ո�tab��س�Ϊֹ)
	  scanf�ǲ���ȫ�ģ���Ϊ��֪��Ҫ��������ݵĳ���
	3.��ȫ������
	  char string[8];
	  scanf("%7s", string);
	  ��%��s֮������ֱ�ʾ������������ַ����������������Ӧ�ñ�����Ĵ�ССһ
	  ��һ��scanf�����￪ʼ?
	4.��������
	  char *string;
	  scanf("%s", string);
	  ��Ϊchar*���ַ������ͣ�������һ���ַ������͵�
	  ����string�Ϳ���ֱ��ʹ����
	  ����û�ж�string��ʼ��Ϊ0�����Բ�һ��ÿ�����ж�����
	5.���ַ���
	  char buffer[100]="";
	  ����һ���յ��ַ�����buffer[0]=='\0'
	  char buffer[]="";
	  �������ĳ���ֻ��1��

*/

int main(void)
{
	char word1[8];
	char word2[8];
	scanf("%7s", word1);	// ����һ������
	scanf("%7s", word2);	//%7s��ʾ������7���ַ������һ���ַ���\0,��ֹԽ��
	printf("%s##%s##\n", word1, word2);

	return 0;
}