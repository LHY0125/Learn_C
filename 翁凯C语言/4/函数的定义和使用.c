#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/*
    ��������:������һ�δ���ķ�װ�������ظ�ʹ��
    ����������:���߱��������������֣������Ĳ���������ֵ����
    �����ĵ���:ʹ�ú��������ú��������������
*/

void num_sum(int begin, int end)
/*
    ������ͷvoid num_sum(int begin, int end)
    void�Ƿ���ֵ����
    num_sum�Ǻ�����
    int�ǲ�������
    begin��end�ǲ�����
*/
{
    // �����壬������Ҫִ�еĴ���
    int sum = 0; 
    for (int i = begin; i <= end; i++)      
    {
        sum += i;
    }
    printf("%d��%d�ĺ�Ϊ%d\n", begin, end, sum);
}

int main()
{
    num_sum(1, 10);
    num_sum(20, 30);
    num_sum(35, 45);

    return 0;
}