#include <stdio.h>

int main()
{
    int a, b, c;
    a = b = c = 0;
    a++ &&b++ | c++;
    printf("%d,%d,%d\n",a,b,c);
    return 0;
}