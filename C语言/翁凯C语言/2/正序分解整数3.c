#include <stdio.h>
#include <stdlib.h>

int num_weishu(int num) {
    int n = 0;
    num = abs(num);
    if (num == 0) return 1;
    while (num > 0) {
        num /= 10;
        n++;
    }
    return n;
}

int main() 
{
    int x, sign = 1;
    printf("������һ��������");
    scanf("%d", &x);

    if (x < 0) 	// ����������
	{
        sign = -1;
        x = -x; // ת��Ϊ��������
    }

    int a = num_weishu(x);
    if (a > 9)
	{
        printf("�������֧��λ����\n");
        return -1;
    } 
	else
	{
        int b=1;
        while (a>0) 
		{
            int m = x/a;	// ��һ������Ӧ�÷���
            if (b) 
			{
                printf("%d", sign*m);
                b = 0;
            } 
			else 
			{
                printf("%d", m);
            }
            x %= a;
            a /= 10;
            if (a > 0) printf(" "); 	//�������ֺ�ӿո�
        }
        printf("\n");
    }

    return 0;
}