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

// !��̬���ر���
/*
    1.��̬���ر���
      �ڱ��ر�������ʱ����static���η��ͳ�Ϊ��̬���ر���
      �������뿪��ʱ�򣬾�̬���ر�����������ڲ�������ֵ
      ��̬���ر����ĳ�ʼ��ֻ���ڵ�һ�ν����������ʱ�����Ժ���뺯��ʱ�ᱣ���ϴ��뿪ʱ��ֵ
    2.��̬���ر�����ȫ�ֱ���������
      ��̬���ر���ʵ�����������ȫ�ֱ���
      ����λ����ͬ���ڴ�����
      ��̬���ر�������ȫ�ֵ������ڣ������ڵľֲ�������
      static���������˼�Ǿֲ�������(���ؿɷ���)
*/

int f(void);

int gALL = 12;

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    f();

    return 0;
}

int f(void)
{
    int k = 0;
    static int gall = 1;
    printf("&gALL=%p\n", &gALL);
    printf("&gall=%p\n", &gall);
    printf("&k   =%p\n", &k);

    printf("in %s gall = %d\n", __func__, gall);
    gall += 2;
    printf("agn in %s gall = %d\n", __func__, gall);

    return 0;
}