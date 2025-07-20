#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// !可变数组
/*
    1.可变数组
*/

typedef struct{
    int *array;
    int size;
} Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int) * a.size);
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    Array a = array_create(100);
    array_free(&a);


    return 0;
}