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

// !�������ĺ�
/*
    1.�����ĺ�
      #define cube(x) ((x)*(x)*(x))
      ����Դ�����
    2.�������ĺ��ԭ��
      һ�ж�Ҫ����
      ����ֵҪ����
      �������ֵ�ÿ���ط���Ҫ����
      #define RADTODEG(x) ((x) * 57.29578)

      ���Դ��������
      #define MIN(a,b) ((a)>(b)?(b):(a))
      Ҳ�������(Ƕ�ף�ʹ��������
    3.�ڴ��ͳ���Ĵ�����ʹ�÷ǳ��ձ�
      ���Էǳ����ӣ��硰����������
      ��#��##������������İ�����
      �����������Ļ�����
      ���ֺ�ᱻinline�������
*/

#define cube(x) ((x)*(x)*(x))

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    printf("cube(5) = %d\n", cube(5));

    return 0;
}