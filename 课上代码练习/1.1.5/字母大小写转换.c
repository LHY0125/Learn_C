#include <stdio.h>

int main()
{
    char c1, c2;
    printf("请输入一个大写字母");
    c1 = getchar();
    c2 = c1 + 32;
    printf("转换后的小写字母为");
    putchar(c2);
    putchar('\n');

    return 0;
}