#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char c = '1';       // '1'是字符常量,不是整数,注意：" "也是字符常量
    char d = 1;         // 1是整数常量,不是字符常量
    printf("%c\n", c);  // %c是字符输出
    printf("%d\n", d);  // %d是整数输出

    char ch;
    scanf("%c", &ch);       // scanf("%c", &c)是字符输入
    printf("ch=%d\n", ch);  // %d是整数输出
    printf("ch='%c'\n", ch);// %c是字符输出

    // !char是一种数据类型，它是用数字编码表示的字符集，比如ASCII码，Unicode码等，也就是说，char类型可以表示一个字符，也可以表示一个整数，具体表示什么，取决于它的编码方式（即输出printf的是%d还是%c）

    // 例如
    char ch1 = 'a';
    ch1++;
    printf("'%c'\n", ch1);  //输出'b'

    return 0;
}
    
