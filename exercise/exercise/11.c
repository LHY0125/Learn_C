#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

#define NUM_COUNT 10000
#define INPUT_FILE "random_numbers.txt"
#define OUTPUT_FILE "sorted_numbers.txt"

/* 选择排序函数 */
void SelectSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        // 假设当前索引i的元素为最小值
        minIndex = i; 
        for (j = i + 1; j < n; j++)
        {
            // 在未排序部分查找更小元素
            if (arr[j] < arr[minIndex])
            {
                // 更新最小值的索引
                minIndex = j;
            }
        }

        // 将找到的最小值与当前位置交换
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

/* 生成随机数并写入文件 */
void MakeRandomNumber(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("错误：无法创建文件 %s\n", filename);
        exit(1);
    }

    // 初始化随机数种子
    srand((unsigned int)time(NULL)); 
    for (int i = 0; i < NUM_COUNT; i++)
    {
        // 生成0-99999范围内的随机数
        fprintf(file, "%d\n", rand() % 100000); 
    }

    fclose(file);
    printf("已生成 %d 个随机数到文件 %s\n", NUM_COUNT, filename);
}

/* 从文件读取数字到数组 */
int ReadNumbers(const char *filename, int arr[])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("错误：无法打开文件 %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%d", &arr[count]) != EOF && count < NUM_COUNT)
    {
        count++;
    }

    fclose(file);
    printf("已从文件 %s 读取 %d 个数字\n", filename, count);
    return count;
}

/* 将数组中的数字写入文件 */
void writeNumbersToFile(const char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("错误：无法创建文件 %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
    printf("已将 %d 个排序后的数字写入文件 %s\n", n, filename);
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

    int numbers[NUM_COUNT];
    int actual_count;
    clock_t start, end;
    double time_used;

    printf("=== 选择排序执行时间测量程序 ===\n");

    // 生成随机数并写入文件
    printf("\n1. 生成随机数...\n");
    MakeRandomNumber(INPUT_FILE);

    // 从文件读取数字到数组
    printf("\n2. 读取文件...\n");
    actual_count = ReadNumbers(INPUT_FILE, numbers);

    // 显示部分未排序数据
    printf("\n3. 未排序数据（前10个）: ");
    for (int i = 0; i < 10 && i < actual_count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 测量选择排序执行时间
    printf("\n4. 开始选择排序...\n");
    // 记录开始时间
    start = clock(); 
    SelectSort(numbers, actual_count);
    // 记录结束时间
    end = clock(); 

    // 计算并显示执行时间
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("选择排序完成！\n");
    printf("执行时间: %.6f 秒\n", time_used);

    // 显示部分已排序数据
    printf("\n6. 已排序数据（前10个）: ");
    for (int i = 0; i < 10 && i < actual_count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 将排序后的数据写入新文件
    printf("\n7. 写入排序结果...\n");
    writeNumbersToFile(OUTPUT_FILE, numbers, actual_count);

    printf("\n=== 程序执行完成 ===\n");
    return 0;
}