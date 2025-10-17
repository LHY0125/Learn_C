#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // 逃逸字符:表示无法直接输入的字符（如换行、制表符）或特殊符号（如双引号、反斜杠本身）
    // 避免语法冲突，例如在字符串中嵌套双引号
    printf("输入\"5 7\"表示5英尺7英寸");

    // \b回退一格
    printf("123\b\n456\n");

    // \t制表符,到下一个表格位(t是tab的缩写，相当于键盘上的tab键)
    printf("12\t456\n");

    // \n换行
    printf("123\n456\n");

    // \r回车
    printf("123\r456\n");

    // \"双引号(")
    printf("123\"456\n");

    // \'单引号(')
    printf("123\'456\n");

    // \\反斜杠(\)
    printf("123\\456\n");

    return 0;
}
    
