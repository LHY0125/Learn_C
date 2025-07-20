#include <stdio.h>

int main()
{
    char c = 'Y';
    putchar(66);    // B
    putchar('O');   // O
    putchar(c);     // Y
    putchar('\n');

    char a, b;
    a = getchar();
    b = getchar();
    putchar(a);
    putchar(b);

    putchar(getchar());

    return 0;
}