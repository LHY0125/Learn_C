#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !����
/*
    [i]��һ�����飬���籾��������������number
    number[0]������ĵ�һ��Ԫ�أ�number[1]������ĵڶ���Ԫ�أ��Դ�����
    ���������Ǵ�0��ʼ

    ������һ���������������е�Ԫ�ض�������ͬ���������ͣ������ڴ��������洢����������
*/

int main()
{
    int x;
    double sum = 0.0;
    int count = 0;
    int number[100]; // ����һ�����飬������Ϊnumber�������СΪ100
    printf("������һ��������");
    scanf("%d", &x);

    while (x != -1)
    {
        if (x < 0 || x != (int)x)   // �ж�����������Ƿ�Ϊ������
        {
            printf("��������ֲ��������������������룡\n");
            continue;
        }
        number[count] = x; // �������е�Ԫ�ؽ��и�ֵ
        count++;
        sum += x;
        printf("������һ��������");
        scanf("%d", &x);
    }

    // ��ֹ����Խ��
    if (count < 100)
    {
        if (count > 0)
        {
            int i;
            double average = sum * 1.0 / count;
            printf("������ܺ���%.0f��ƽ������%.2f��������λС����������ƽ������\n", sum, average);

            for (i = 0; i < count; i++)
            {
                if (number[i] >= average) // sʹ�������е�Ԫ�أ��������е�Ԫ����ƽ�������бȽ�
                {
                    printf("%d ", number[i]); // ��������д���ƽ������Ԫ��
                }
            }
        }
        else
        {
            printf("����Ϊ��,���������룡\n");
        }
    }
    else
    {
        printf("����Ĺ涨��С��100,�����Ѿ������ˣ�\n");
    }

    return 0;
}