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

// !可变数组的数据访问
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

// 封装
int array_size(const Array *a)
{
    return a->size;
}

int* array_at(Array *a, int index)
{
    if (index >= a->size)
    {
        a->size = index + 1;
        a->array = (int *)realloc(a->array, sizeof(int) * a->size);
    }
    return &a->array[index];
}

int array_get(const Array *a, int index)
{
    return a->array[index];
}

void array_set(Array *a, int index, int value)
{
    a->array[index] = value;
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
    printf("%d\n", array_size(&a));

    *array_at(&a, 0) = 10;
    printf("%d\n", *array_at(&a, 0));
    array_free(&a);


    return 0;
}