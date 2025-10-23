#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

int main()
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
    _mkdir("records");
#endif

    // 输入一个十进制整数
    unsigned int n;
    printf("请输入一个正十进制整数: ");

    // 转换为二进制
    char new_num[33]; // 32位二进制数 + 1位结束符
    int index = 0;
    unsigned int temp = n;

    // 从低位到高位计算二进制位
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            new_num[index] = '0';
        }
        else
        {
            new_num[index] = '1';
        }
        n /= 2;
        index++;
    }

    // 添加字符串结束符
    new_num[index] = '\0';
    
    // 反转字符串
    int len = strlen(new_num);
    for (int i = 0; i < len / 2; i++)
    {
        char use_char = new_num[i];
        new_num[i] = new_num[len - 1 - i];
        new_num[len - 1 - i] = use_char;
    }

    // 输出结果
    printf("十进制数 %u 对应的二进制表示为: %s\n", temp, new_num);

    return 0;
}