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

�����Ǹú������ĵ�ע��:

/**
 * @brief �����begin��end֮�����������ĺ�
 * @param begin ��ʼ��(����)
 * @param end ������(����) 
 * @return ���������������������ۼӺ�
 * @note begin����С�ڵ���end
 */
int num_sum(int begin, int end)
/*
    ������ͷvoid num_sum(int begin, int end)
    int�Ƿ���ֵ���ͣ�int��Ҫ����һ��ֵ����void����Ҫ����ֵ
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
    return sum; // �����ķ���ֵ��return����
}

int main()
{
    printf("%d\n", num_sum(1, 10));
    printf("%d\n", num_sum(20, 30));
    printf("%d\n", num_sum(35, 45));

    return 0;
}