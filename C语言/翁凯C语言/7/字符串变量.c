#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !
/*
	1.�ַ�������
	  char*s = "Hello, world!";
	  s��һ��ָ�룬��ʼ��Ϊָ��һ���ַ�������
	  ��������������ڵĵط�������ʵ����s��const char*s������������ʷ��ԭ�򣬱��������ܲ���const��д��
	  ������ͼ��s��ָ���ַ�����д��ᵼ�����صĺ��
	  �����Ҫ�޸��ַ�����Ӧ��������:
	  char s[] = "Hello, world!";
	2.ָ�뻹������?
	  char *str ="Hello"
	  char word[]="Hello"
	  ���飺����ַ���������
	  ��Ϊ���ر����ռ��Զ�������
	  ָ�룺����ַ�����֪��������
	  �������
	  ��̬����ռ�
	3.char*���ַ�����
	  �ַ������Ա��Ϊchar*����ʽ
	  char*��һ�����ַ���
	  ������ָ���ַ���ָ�룬����ָ������ַ������飨����int*һ����
	  ֻ������ָ���ַ������н�β��0������˵����ָ�����ַ���
*/

int main(void)
{
	/* 1.�ַ����Ķ��� */
	char *s="Hello World!";
	char *s2 = "Hello World!";
	char s3[] = "Hello World!";
	s[0] = 'B';

	printf("s =%p\n", s );
	printf("s2=%p\n", s2);
	printf("s3=%p\n", s3);
	s3[0] = 'B';
	printf("Here!s3[0]=%c\n", s3[0]);
	printf("Here!s[0]=%c\n", s[0]);

	return 0;
}