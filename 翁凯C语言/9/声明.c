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

// !����
/*
    1.����������
      int i;�Ǳ����Ķ���
      extern int i;�Ǳ���������
    2.�����Ͷ���
      �����ǲ���������Ķ���
      ����ԭ��
      ��������
      �ṹ����
      ������
      ö������
      ��������
      inline��������
      �ǲ�������Ķ���
    3.ͷ�ļ�
      ֻ���������Ա�����ͷ�ļ���
      �ǹ����Ƿ���
      ��������һ����Ŀ�ж�����뵥Ԫ����������ʵ��
      *ĳЩ���������������뵥Ԫ�д���ͬ���ĺ�����������weak���η���ǿ�����ִ���
    4.�ظ�����
      ͬһ�����뵥Ԫ��,ͬ���Ľṹ���ܱ��ظ�����
      ������ͷ�ļ����нṹ���������������ͷ�ļ�������һ�����뵥Ԫ�ﱻ#include���
      ������Ҫ����׼ͷ�ļ��ṹ��
    5.��׼ͷ�ļ��ṹ
      #ifndef __LIST_HEAD__
      #define __LIST_HEAD__

      #include "node.h" 
      typedef struct _list { 
          Node* head;
          Node* tail;
      } List; 

      #endif 
      ������������ͺ꣬��֤���ͷ�ļ���һ�����뵥Ԫ��ֻ�ᱻ#includeһ��
      #pragma onceҲ������ͬ�����ã����ǲ������еı�������֧��
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