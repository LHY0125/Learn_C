#include <stdio.h>

int main()
{
    char c1, c2;
    printf("������һ����д��ĸ");
    c1 = getchar();
    c2 = c1 + 32;
    printf("ת�����Сд��ĸΪ");
    putchar(c2);
    putchar('\n');

    return 0;
}