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

// !��ʽ���������
/*
    1.��ʽ�����������
      printf
      %[flags][width][.prec][hlL]type
      scanf
      %[flag]type
    2.printf��scanf�ķ���ֵ
      �������Ŀ��
      ������ַ���
      ��Ҫ���ϸ�ĳ����У�Ӧ���ж�ÿ�ε���scanf��print�ķ���ֵ���Ӷ��˽�����������Ƿ��������
*/

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    printf("%+9d\n", 123);
    printf("%+9d\n", -123);
    printf("%-9d\n", 123);

    printf("%+09d\n", 123);
    printf("%+09d\n", -123);

    int n;
    printf("%dty%n\n", 12345, &n);

    return 0;
}