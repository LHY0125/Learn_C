#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // !�������ķ�Χ
    printf("%f\n", 12.0/0.0);   //12/0��û�ж���ģ���ֻ�и�����������������С
    printf("%f\n", -12.0/0.0);
    printf("%f\n", 0.0/0.0);
    //inf�������nan������С

    // !�������ľ���
    float a, b, c;
    a = 1.345f;     //��С�����Ĭ����double���ͣ�����Ҫ��f��ָ����float����
    b = 1.123f;
    c = a + b;
    if (c== 2.468)
    {
        printf("c = 2.468\n");
    }
    else
    {
        printf("����ȣ� c=%.10f,��%f\n", c, c);
    }

    return 0;
}