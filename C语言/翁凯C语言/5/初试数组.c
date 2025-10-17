#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !数组
/*
    [i]是一个数组，例如本代码中数组名是number
    number[0]是数组的第一个元素，number[1]是数组的第二个元素，以此类推
    即从左到右是从0开始

    数组是一种容器，其中所有的元素都具有相同的数据类型，且在内存中连续存储，依次排列
*/

int main()
{
    int x;
    double sum = 0.0;
    int count = 0;
    int number[100]; // 定义一个数组，数组名为number，数组大小为100
    printf("请输入一个整数：");
    scanf("%d", &x);

    while (x != -1)
    {
        if (x < 0 || x != (int)x)   // 判断输入的数字是否为正整数
        {
            printf("输入的数字不是正整数，请重新输入！\n");
            continue;
        }
        number[count] = x; // 对数组中的元素进行赋值
        count++;
        sum += x;
        printf("请输入一个整数：");
        scanf("%d", &x);
    }

    // 防止数组越界
    if (count < 100)
    {
        if (count > 0)
        {
            int i;
            double average = sum * 1.0 / count;
            printf("数组的总和是%.0f，平均数是%.2f（保留两位小数），大于平均数有\n", sum, average);

            for (i = 0; i < count; i++)
            {
                if (number[i] >= average) // s使用数组中的元素，将数组中的元素与平均数进行比较
                {
                    printf("%d ", number[i]); // 输出数组中大于平均数的元素
                }
            }
        }
        else
        {
            printf("数组为空,请重新输入！\n");
        }
    }
    else
    {
        printf("数组的规定大小是100,现在已经超过了！\n");
    }

    return 0;
}