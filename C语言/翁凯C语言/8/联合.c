#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !����
/*
    1.�洢
      ���еĳ�Ա����һ���ռ�
      ͬһʱ��ֻ��һ����Ա����Ч��
      union�Ĵ�С�������ĳ�Ա
    2.��ʼ��
      �Ե�һ����Ա����ʼ��
*/
typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;

int main()
{ 
    CHI chi;
    int i;
    chi.i = 1234;
    for ( i=0; i<sizeof(int); i++)
    {
        printf("%02hhx", chi.ch[i]); 
    } 
    printf("\n");

    return 0;
}