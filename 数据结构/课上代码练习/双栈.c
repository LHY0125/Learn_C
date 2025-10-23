#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

typedef int Status;    // 函数返回状态
typedef int SElemType; // 栈元素类型

typedef struct 
{
    int top[2], bot[2]; // 栈顶和栈底指针
    SElemType *V;       // 栈数组
    int m;              // 栈的最大容量
} DblStack;

// 双栈的初始化
Status Init(DblStack *s, int m)
{
    // 容量无效
    if (m <= 0)
    {
        return 0; 
    }
    s->V = (SElemType *)malloc(m * sizeof(SElemType));
    if (!s->V)
    {
        return -1; // 内存分配失败
    }

    s->m = m;
    // 0号栈空时栈顶指针为-1
    s->top[0] = -1;
    s->bot[0] = 0;
    // 1号栈空时栈顶指针为m
    s->top[1] = m;
    s->bot[1] = m - 1;

    return 1;
}

// 双栈的销毁
void Destroy(DblStack *s)
{
    if (s->V)
    {
        free(s->V);
        s->V = NULL;
    }
    s->m = 0;
    s->top[0] = -1;
    s->top[1] = 0;
    s->bot[0] = s->bot[1] = 0;
}

// 判断栈是否为空
Status IsEmpty(DblStack s, int Num)
{
    // 栈号无效
    if (Num != 0 && Num != 1)
    {
        return 0;
    } 
    // 判断栈是否为空 
    if (Num == 0)
    {
        // 0号栈空：top[0] = -1
        if (s.top[0] == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        // 1号栈空：top[1] = m
        if (s.top[1] == s.m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// 判断双栈是否已满
Status IsFull(DblStack s)
{
    // 两栈顶相遇
    if (s.top[0] + 1 == s.top[1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 进栈操作
Status Push(DblStack *s, int Num, SElemType e)
{
    // 栈号无效
    if (Num != 0 && Num != 1)
    {
        return 0;
    } 
    if (IsFull(*s) == 1)
    {
        printf("双栈已满，无法进栈！\n");
        return 0;
    }

    if (Num == 0)
    {
        // 0号栈：栈顶指针上移（+1），元素存入新栈顶
        s->top[0]++;
        s->V[s->top[0]] = e;
    }
    else
    {
        // 1号栈：栈顶指针下移（-1），元素存入新栈顶
        s->top[1]--;
        s->V[s->top[1]] = e;
    }
    return 1;
}

// 出栈操作
Status Pop(DblStack *s, int Num, SElemType *e)
{
    // 栈号无效
    if (Num != 0 && Num != 1)
    {
        return 0;
    }
    if (IsEmpty(*s, Num) == 1)
    {
        printf("栈%d为空，无法出栈！\n", Num);
        return 0;
    }

    if (Num == 0)
    {
        // 0号栈：取出当前栈顶元素，栈顶指针下移（-1）
        *e = s->V[s->top[0]];
        s->top[0]--;
    }
    else
    {
        // 1号栈：取出当前栈顶元素，栈顶指针上移（+1）
        *e = s->V[s->top[1]];
        s->top[1]++;
    }
    return 1;
}

// 获取栈顶元素
Status GetTop(DblStack s, int Num, SElemType *e)
{
    // 栈号无效
    if (Num != 0 && Num != 1)
    {
        return 0;
    } 
    if (IsEmpty(s, Num) == 1)
    {
        printf("栈%d为空，无栈顶元素！\n", Num);
        return 0;
    }

    if (Num == 0)
    {
        *e = s.V[s.top[0]]; // 0号栈顶元素
    }
    else
    {
        *e = s.V[s.top[1]]; // 1号栈顶元素
    }
    return 1;
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

    DblStack s;
    int m = 5; // 双栈总容量为5
    SElemType e;

    // 初始化双栈
    if (Init(&s, m) != 1)
    {
        printf("双栈初始化失败！\n");
        return -1;
    }
    printf("初始化双栈成功（容量：%d）\n", m);

    // 测试栈空
    printf("栈0是否为空？%s\n", IsEmpty(s, 0) == 1 ? "是" : "否"); // 是
    printf("栈1是否为空？%s\n", IsEmpty(s, 1) == 1 ? "是" : "否"); // 是

    // 0号栈进栈
    Push(&s, 0, 10);
    Push(&s, 0, 20);
    Push(&s, 0, 30);
    printf("0号栈进栈元素：10, 20, 30\n");
    GetTop(s, 0, &e);
    printf("0号栈顶元素：%d\n", e); // 30

    // 1号栈进栈
    Push(&s, 1, 100);
    Push(&s, 1, 200);
    printf("1号栈进栈元素：100, 200\n");
    GetTop(s, 1, &e);
    printf("1号栈顶元素：%d\n", e); // 200

    // 测试栈满（此时0号栈顶=2，1号栈顶=3，2+1=3 → 满）
    printf("双栈是否已满？%s\n", IsFull(s) == 1 ? "是" : "否"); // 是

    // 尝试继续进栈（应失败）
    Push(&s, 0, 40); // 提示"双栈已满"

    // 出栈操作
    Pop(&s, 0, &e);
    printf("0号栈出栈元素：%d\n", e); // 30
    Pop(&s, 1, &e);
    printf("1号栈出栈元素：%d\n", e); // 200

    // 出栈后栈顶
    GetTop(s, 0, &e);
    printf("0号栈顶元素（出栈后）：%d\n", e); // 20
    GetTop(s, 1, &e);
    printf("1号栈顶元素（出栈后）：%d\n", e); // 100

    // 销毁双栈
    Destroy(&s);
    printf("双栈销毁完成\n");

    return 0;
}