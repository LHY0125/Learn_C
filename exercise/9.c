#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 删除数组中下标为 i 的元素
void del(int a[], int n, int i)
{
    if (i < 0 || i >= n)
    {
        printf("下标超出范围\n");
        return;
    }
    for (int j = i; j < n - 1; j++)
    {
        a[j] = a[j + 1];
    }
}

// 输出数组的前 n 个元素
void PrintArr(int a[], int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("%d", a[j]);
        if (j < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
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

    int n;
    scanf("%d", &n);

    if (n <= 0 || n >= 10)
    {
        printf("数组长度不合法\n");
        return 1;
    }

    int a[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int index;
    scanf("%d", &index);

    if (index < 0 || index >= n)
    {
        printf("下标超出范围\n");
        return 1;
    }

    del(a, n, index);
    PrintArr(a, n - 1);

    return 0;
}