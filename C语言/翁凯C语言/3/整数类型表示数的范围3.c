#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{ 
    int a = 0;
    int b = 1;

    while (++a>0)
    {
        ;
    }
    printf("int�����ֵ�ǣ�%d\n", a-1);

    while ((a=a/10)!=0)
    {
        b++;
    }
    printf("int��λ���ǣ�%d\n", b);

    return 0;

}