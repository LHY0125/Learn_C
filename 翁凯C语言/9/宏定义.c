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

// !�궨��
/*
    1.��Ԥ����ָ��
      #��ͷ���Ǳ���Ԥ����ָ��
      ���ǲ���C���Եĳɷ֣�����C���Գ����벻������
      #define��������һ����
    2.#define
      #define <����> <ֵ>
      ע��û�н�β�ķֺţ���Ϊ����C�����
      ���ֱ�����һ�����ʣ�ֵ�����Ǹ��ֶ���
      ��C���Եı�������ʼ����֮ǰ������Ԥ�������(cpp)��ѳ����е����ֻ���ֵ
      ��ȫ���ı��滻
      gcc --save-temps
    3.��
      ���һ�����ֵ���������ĺ�����֣�Ҳ�ǻᱻ�滻��
      ���һ�����ֵ����һ�У����һ��֮ǰ����ĩ��Ҫ��\
      ���ֵ������ֵ�ע�Ͳ��ᱻ�������ֵ��һ����
    4.û��ֵ�ĺ�
      #define_DEBUG
      �������������������ģ������������ı���Ԥ����ָ�������������Ƿ��Ѿ����������
    5.Ԥ����ĺ�
      __LINE__  //��ǰ�к�
      __FILE__  //��ǰ�ļ���
      __DATE__  //��ǰ����
      __TIME__  //��ǰʱ��  
      __STDC__  //�����������ѭANSI C����ֵΪ1
*/

#define PI 3.1415926

int main()
{
    // ���ÿ���̨����ΪUTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // ���ÿ���̨����ΪUTF-8
    SetConsoleOutputCP(65001);  // ���ÿ���̨�������
    SetConsoleCP(65001);        // ���ÿ���̨�������
#endif

    printf("%f\n", 2*PI*3.0);

    return 0;
}