#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()  //�Լ��������֣��Լ���
{
    int a, b, c, d;
    printf("������һ����Ƶ����������������");
    scanf("%d %d", &a, &b);
    while(c!=a)
    {
        c = 0;
        d = 1;
        d++;
        printf("������һ����������");
        scanf("%d", &c);
        if(c>a)
        {
            printf("���ˣ�\n");
        }
        else if(c<a)
        {
            printf("С�ˣ�\n");
        }
        else
        {
            d++;
            if (d <= b)
            {
                printf("��ֻ����%d�Σ��Ͳ¶��ˣ�\n", d);
            }
            else
            {
                printf("��һ������%d�Σ��Ų¶ԣ�\n", d);
            }
        }
    }
    return 0;
}