#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// !ȫ�ֱ���
/*
	1.�����ں�������ı�����ȫ�ֱ���
	2.ȫ�ֱ�������ȫ�ֵ������ں�������
	  �������κκ������޹�
	  ���κκ����ڲ�������ʹ������
	3.ȫ�ֱ�����ʼ��
	  û������ʼ����ȫ�ֱ�����õ�0ֵ
	  ָ���õ�NULLֵ
	  ֻ���ñ���ʱ����֪��ֵ����ʼ��ȫ�ֱ���
	  ���ǵĳ�ʼ��������main����֮ǰ
	4.�����ص�ȫ�ֱ���
	  ��������ڲ�������ȫ�ֱ���ͬ���ı�������ȫ�ֱ���������
*/

int f(void);

int gALL = 12;

int main()
{
	// ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
	system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
	SetConsoleOutputCP(65001);	// ���ÿ���̨�������
	SetConsoleCP(65001);		// ���ÿ���̨�������
#endif

	printf("in %s gALL = %d\n", __func__, gALL);
	f();
	printf("in %s gALL = %d\n", __func__, gALL);

	return 0;
}

int f(void)
{
	printf("in %s gALL = %d\n", __func__, gALL);
	gALL+=2;
	printf("in %s gALL = %d\n", __func__, gALL);

	return 0;
}