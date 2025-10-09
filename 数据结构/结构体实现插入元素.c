#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 定义结构体
typedef struct MyArray
{
    int arr[100]; // 数组，假设最大长度为100
    int size;     // 数组当前元素数量
} MyArray;

// 插入函数，作为结构体外部的成员函数
void insert(MyArray *myArray, int position, int value)
{
    if (position < 0 || position > myArray->size || myArray->size >= 100)
    {
        // 处理错误情况，例如位置无效或数组已满
        printf("Error: Invalid position or array is full.\n");
        return;
    }

    // 将从插入位置开始的元素向后移动一位
    for (int i = myArray->size; i > position; i--)
    {
        myArray->arr[i] = myArray->arr[i - 1];
    }

    // 在指定位置插入新值
    myArray->arr[position] = value;

    // 更新数组大小
    myArray->size++;
}

// 查找函数，返回指定值在数组中的位置，如果未找到返回-1
int search(const MyArray *myArray, int value)
{
    for (int i = 0; i < myArray->size; i++)
    {
        if (myArray->arr[i] == value)
        {
            return i; // 返回找到的位置
        }
    }
    return -1; // 未找到，返回-1
}

// 删除函数，删除指定位置的元素
void delete(MyArray *myArray, int position)
{
    if (position < 0 || position >= myArray->size)
    {
        // 处理错误情况，例如位置无效
        printf("Error: Invalid position.\n");
        return;
    }

    // 将从删除位置后的元素向前移动一位
    for (int i = position; i < myArray->size - 1; i++)
    {
        myArray->arr[i] = myArray->arr[i + 1];
    }

    // 更新数组大小
    myArray->size--;
}

// 安全输入函数，获取用户输入的整数值并进行范围检查
int getInput(const char *prompt, int min, int max)
{
    int value;
    char buffer[100];
    
    while (1)
    {
        printf("%s", prompt);
        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // 尝试解析整数
            char *endptr;
            value = strtol(buffer, &endptr, 10);
            
            // 检查是否为有效整数
            if (endptr != buffer && (*endptr == '\n' || *endptr == '\0'))
            {
                // 检查范围
                if (value >= min && value <= max)
                {
                    return value;
                }
                else
                {
                    printf("错误：输入值必须在 %d 到 %d 之间！\n", min, max);
                }
            }
            else
            {
                printf("错误：请输入有效的整数！\n");
            }
        }
        else
        {
            printf("错误：读取输入失败！\n");
        }
    }
}

// 菜单选择输入函数
int getMenuChoice()
{
    return getInput("请选择操作 (1-5): ", 1, 5);
}

// 打印函数，作为结构体外部的成员函数
void print(const MyArray *myArray)
{
    for (int i = 0; i < myArray->size; i++)
    {
        printf("%d ", myArray->arr[i]); // 打印数组元素
    }
    printf("\n"); // 换行
}

int main(void)
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
    _mkdir("records");
#endif

    MyArray myArray; // 创建MyArray实例
    int choice, position, value, foundPos;

    // 初始化数组和size
    for (int i = 0; i < 5; i++)
    {
        myArray.arr[i] = i + 1;
    }
    myArray.size = 5; // 设置数组当前大小

    printf("初始数组: ");
    print(&myArray);

    while (1)
    {
        // 显示菜单
        printf("\n=== 数组操作菜单 ===\n");
        printf("1. 插入元素\n");
        printf("2. 查找元素\n");
        printf("3. 删除元素\n");
        printf("4. 打印数组\n");
        printf("5. 退出程序\n");
        printf("请选择操作 (1-5): ");

        choice = getMenuChoice();

        switch (choice)
        {
        case 1: // 插入元素
            {
                char prompt[100];
                sprintf(prompt, "请输入要插入的位置 (0-%d): ", myArray.size);
                position = getInput(prompt, 0, myArray.size);
                value = getInput("请输入要插入的值 (-1000到1000): ", -1000, 1000);
                insert(&myArray, position, value);
                printf("插入操作完成!\n");
            }
            break;

        case 2: // 查找元素
            value = getInput("请输入要查找的值 (-1000到1000): ", -1000, 1000);
            foundPos = search(&myArray, value);
            if (foundPos != -1)
            {
                printf("找到元素 %d 在位置 %d\n", value, foundPos);
            }
            else
            {
                printf("未找到元素 %d\n", value);
            }
            break;

        case 3: // 删除元素
            {
                if (myArray.size == 0)
                {
                    printf("错误：数组为空，无法删除元素！\n");
                    break;
                }
                char prompt[100];
                sprintf(prompt, "请输入要删除的位置 (0-%d): ", myArray.size - 1);
                position = getInput(prompt, 0, myArray.size - 1);
                delete(&myArray, position);
                printf("删除操作完成!\n");
            }
            break;

        case 4: // 打印数组
            printf("当前数组: ");
            print(&myArray);
            break;

        case 5: // 退出程序
            printf("程序退出，再见!\n");
            return 0;

        default:
            printf("无效选择，请重新输入!\n");
            break;
        }
    }

    return 0;
}