#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !联合
/*
    1.存储
      所有的成员共享一个空间
      同一时间只有一个成员是有效的
      union的大小是其最大的成员
    2.初始化
      对第一个成员做初始化
*/
typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;

int main()
{ 
    CHI chi;
    int i;
    chi.i = 1234;
    for ( i=0; i<sizeof(int); i++)
    {
        printf("%02hhx", chi.ch[i]); 
    } 
    printf("\n");

    return 0;
}