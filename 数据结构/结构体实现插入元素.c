#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

/**
 * @brief 将指令复制到powershell
 * gcc "数据结构\结构体实现插入元素.c" -o output/结构体实现插入元素.exe
  .\output\结构体实现插入元素.exe
 */

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

// 修改函数，修改指定位置的元素值
void modify(MyArray *myArray, int position, int newValue)
{
    if (position < 0 || position >= myArray->size)
    {
        // 处理错误情况，例如位置无效
        printf("Error: Invalid position.\n");
        return;
    }

    // 修改指定位置的值
    myArray->arr[position] = newValue;
    printf("成功将位置 %d 的值修改为 %d\n", position, newValue);
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

// 排序函数，使用冒泡排序对数组进行升序排序
void sort(MyArray *myArray)
{
    if (myArray->size <= 1)
    {
        printf("数组元素不足，无需排序\n");
        return;
    }

    // 冒泡排序算法 - 将数组按升序排列
    // 外层循环：控制排序的轮数，每轮确定一个最大元素的最终位置
    for (int i = 0; i < myArray->size - 1; i++)
    {
        // 内层循环：在未排序部分进行相邻元素比较和交换
        // 每轮循环后，最大元素会"冒泡"到数组末尾
        // myArray->size - 1 - i：随着i增加，已排序部分增大，需要比较的元素减少
        for (int j = 0; j < myArray->size - 1 - i; j++)
        {
            // 比较相邻两个元素，如果前面的元素大于后面的元素
            if (myArray->arr[j] > myArray->arr[j + 1])
            {
                // 交换两个元素的位置，使较大的元素向后移动
                // 使用临时变量temp保存第一个元素的值
                int temp = myArray->arr[j];
                // 将第二个元素的值赋给第一个位置
                myArray->arr[j] = myArray->arr[j + 1];
                // 将临时保存的值赋给第二个位置，完成交换
                myArray->arr[j + 1] = temp;
            }
        }
    }
    printf("数组排序完成（升序）\n");
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
    return getInput("请选择操作 (1-7): ", 1, 7);
}

// 获取插入位置的输入函数
int getInsertPosition(const MyArray *myArray)
{
    char prompt[100];
    sprintf(prompt, "请输入要插入的位置 (0-%d): ", myArray->size);
    return getInput(prompt, 0, myArray->size);
}

// 获取有效位置的通用输入函数（用于删除和修改操作）
int getValidPosition(const MyArray *myArray, const char *operation)
{
    if (myArray->size == 0)
    {
        printf("错误：数组为空，无法%s元素！\n", operation);
        return -1;
    }
    char prompt[100];
    sprintf(prompt, "请输入要%s的位置 (0-%d): ", operation, myArray->size - 1);
    return getInput(prompt, 0, myArray->size - 1);
}

// 获取删除位置的输入函数
int getDeletePosition(const MyArray *myArray)
{
    return getValidPosition(myArray, "删除");
}

// 获取修改位置的输入函数
int getModifyPosition(const MyArray *myArray)
{
    return getValidPosition(myArray, "修改");
}

// 获取元素值的输入函数
int getElementValue(const char *operation)
{
    char prompt[100];
    sprintf(prompt, "请输入要%s的值 (-1000到1000): ", operation);
    return getInput(prompt, -1000, 1000);
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
        printf("2. 删除元素\n");
        printf("3. 修改元素\n");
        printf("4. 查找元素\n");
        printf("5. 排序数组\n");
        printf("6. 打印数组\n");
        printf("7. 退出程序\n");
        printf("请选择操作 (1-7): ");

        choice = getMenuChoice();

        switch (choice)
        {
        case 1: // 插入元素
        {
            printf("当前数组: ");
            print(&myArray);
            position = getInsertPosition(&myArray);
            value = getElementValue("插入");
            insert(&myArray, position, value);
            printf("插入操作完成!\n");
        }
        break;

        case 2: // 删除元素
        {
            printf("当前数组: ");
            print(&myArray);
            position = getDeletePosition(&myArray);
            if (position != -1)
            {
                delete(&myArray, position);
                printf("删除操作完成!\n");
            }
        }
        break;

        case 3: // 修改元素
        {
            printf("当前数组: ");
            print(&myArray);
            position = getModifyPosition(&myArray);
            if (position != -1)
            {
                printf("当前位置 %d 的值为: %d\n", position, myArray.arr[position]);
                value = getElementValue("修改为");
                modify(&myArray, position, value);
            }
        }
        break;

        case 4: // 查找元素
            printf("当前数组: ");
            print(&myArray);
            value = getElementValue("查找");
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

        case 5: // 排序数组
            printf("排序前数组: ");
            print(&myArray);
            sort(&myArray);
            printf("排序后数组: ");
            print(&myArray);
            break;

        case 6: // 打印数组
            printf("当前数组: ");
            print(&myArray);
            break;

        case 7: // 退出程序
            printf("程序退出，再见!\n");
            return 0;

        default:
            printf("无效选择，请重新输入!\n");
            break;
        }
    }

    return 0;
}