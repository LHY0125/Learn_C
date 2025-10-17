#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int main()
{ 
    // !#include <stdbool.h>之后，bool类型就可用，即true和false
    // 逻辑运算符：&&（与）、||（或）、！（非）
    // 逻辑运算符的优先级低于关系运算符，高于算术运算符
    // 逻辑运算符的运算对象和求值结果都是bool类型
    // 逻辑运算符的运算对象可以是任意能转换成bool类型的值

    bool b = 6 > 5; // b为true
    bool t = true;
    t = 2;
    printf("%d\n", t);  // bool类型只能以%d输出,即结果为1

    return 0;
}
    
