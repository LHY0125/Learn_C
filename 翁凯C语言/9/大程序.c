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

// !�����
/*
    1.���.c�ļ�
      main()��Ĵ���̫�����ʺϷֳɼ�������
      һ��Դ�����ļ�̫�����ʺϷֳɼ����ļ�
      ����������Դ�����ļ����ܱ����γɿ�ִ�еĳ���
    2.��Ŀ
      ��Dev C++���½�һ����Ŀ��Ȼ��Ѽ���Դ�����ļ������ȥ
      ������Ŀ,Dev C++�ı�����һ����Ŀ�����е�Դ�����ļ����������������
      �е�IDE�зֿ��ı���͹���������ť��ǰ���ǶԵ���Դ�����ļ����룬�����Ƕ�������Ŀ������
    3.���뵥Ԫ
      һ��.c�ļ���һ�����뵥Ԫ������ÿ�α���ֻ����һ�����뵥Ԫ
*/

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    

    return 0;
}