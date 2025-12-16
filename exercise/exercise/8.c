#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

#define MAX_SIZE 10

typedef struct
{
    int data[MAX_SIZE]; // 存储数据的数组
    int length;         // 当前顺序表长度
} List;

// 初始化顺序表
void InitList(List *L)
{
    L->length = 0;
    memset(L->data, 0, sizeof(L->data));
}

// 判断顺序表是否已满
int IsFull(List *L)
{
    return L->length == MAX_SIZE;
}

// 在指定位置插入元素
int InsertLoc(List *L, int loc, int value)
{
    if (IsFull(L))
    {
        return 0;
    }
    if (loc < 1 || loc > L->length + 1)
    {
        return 0;
    }

    // 将插入位置后的元素后移
    for (int i = L->length; i >= loc; i--)
    {
        L->data[i] = L->data[i - 1];
    }

    // 插入新元素和更新长度
    L->data[loc - 1] = value;
    L->length++;

    return 1;
}

// 显示顺序表内容
void DisplayList(List *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n", L->data[i]);
    }
}

int main()
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
    _mkdir("records");
#endif

    List L;
    InitList(&L);

    // 插入一些元素以测试
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &L.data[i]);
        L.length++;
    }

    // 验证输入数组是否有序
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < L.data[i - 1])
        {
            printf("输入数组未按升序排列\n");
            return 1;
        }
    }

    // 找到value插入的位置
    int value, loc;
    scanf("%d", &value);
    // 默认插入到最后
    loc = L.length + 1;
    for (int i = 0; i < L.length; i++)
    {
        if (value <= L.data[i])
        {
            loc = i + 1;
            break;
        }
    }

    // 插入元素
    if (L.length >= MAX_SIZE)
    {
        printf("插入失败：顺序表已满\n");
        return 1;
    }
    if (!InsertLoc(&L, loc, value))
    {
        printf("插入失败\n");
        return 1;
    }

    // 显示顺序表内容
    DisplayList(&L);

    return 0;
}