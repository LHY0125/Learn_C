#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    /*
        条件运算符：?:
        条件运算符的优先级低于关系运算符，高于算术运算符
        条件运算符的运算对象和求值结果都是int类型
        条件运算符的运算对象可以是任意能转换成int类型的值
    */
    int count = 0;
    scanf("%d",&count);
    count=(count>20)?count-10:-count+10;
    /*
        等价于
        if (count>20)
            count=count-10;
        else
            count=-count+10;
    */

    /*
        逗号运算符：,:
        逗号用来连接两个表达式，并以其右边的表达式的值做为他的结果
        逗号运算符的优先级在所有运算符中是最低的，所以他的两边的运算对象会先求值
        逗号的组合关系是从左向右的，所以左边的运算对象会先求值，而右边的表达式的值就会留下来作为整个逗号表达式的值
    */
    int i;
    int j;
    i = 3 + 4, 5 + 6;
    printf("%d\n", i);  
    // 结果是7，因为逗号运算符的优先级最低，所以i=3+4,5+6;这个表达式等价于i=(3+4),(5+6);
    
    // 例如
    for (i = 0, j = 10; i < j;i++,j--)
    {
        printf("%d %d\n", i, j);
    }

    return 0;
}