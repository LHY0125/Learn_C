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

// !����ָ��ĺ���
/*
    1.*����ָ��ĺ���
      ���ر��ر����ĵ�ַ��Σ�յ�
      ����ȫ�ֱ�����̬���ر����ĵ�ַ�ǰ�ȫ��
      �����ں�����malloc���ڴ��ǰ�ȫ�ģ����������������
      ��õ������Ƿ��ش����ָ��
    2.tips
      ��Ҫʹ��ȫ�ֱ������ں����䴫�ݲ����ͽ��
      ��������ʹ��ȫ�ֱ���
      ���������İ���
      *ʹ��ȫ�ֱ����;�̬���ر����ĺ������̲߳���ȫ��
*/

int *f(void);
void g(void);

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    int *p=f();
    printf("*p = %d\n", *p);
    g();
    printf("*p = %d\n", *p);

    return 0;
}

int *f(void)
{
    int i=12;
    return &i;
}

void g(void)
{
    int k = 14;
    printf("k = %d\n", k);
}