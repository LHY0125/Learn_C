#include <stdio.h>
#include <stdlib.h>

// 宏定义：状态码与元素类型
typedef int Status;    // 函数返回状态
typedef int SElemType; // 栈元素类型（可根据需求修改，如char、float等）

// 双栈数据结构定义（题目给定）
typedef struct
{
    int top[2], bot[2]; // 栈顶、栈底指针（top[0]对应0号栈，top[1]对应1号栈）
    SElemType *V;       // 共享的数组空间
    int m;              // 数组最大容量（双栈总容量）
} DblStack;

/**
 * 初始化双栈
 * @param s 双栈指针
 * @param m 数组最大容量
 * @return 初始化成功返回OK，内存分配失败返回OVERFLOW
 */
Status InitDblStack(DblStack *s, int m)
{
    if (m <= 0)
        return 0; // 容量无效
    s->V = (SElemType *)malloc(m * sizeof(SElemType));
    if (!s->V)
        return -1; // 内存分配失败

    s->m = m;
    // 初始化0号栈：栈底在数组起始位置（索引0），空栈时top[0] = -1
    s->top[0] = -1;
    s->bot[0] = 0;
    // 初始化1号栈：栈底在数组末尾（索引m-1），空栈时top[1] = m
    s->top[1] = m;
    s->bot[1] = m - 1;

    return 1;
}

/**
 * 销毁双栈（释放内存）
 * @param s 双栈指针
 */
void DestroyDblStack(DblStack *s)
{
    if (s->V)
    {
        free(s->V); // 释放数组空间
        s->V = NULL;
    }
    s->m = 0;
    s->top[0] = -1;
    s->top[1] = 0;
    s->bot[0] = s->bot[1] = 0;
}

/**
 * 判断指定栈是否为空
 * @param s 双栈
 * @param stackNum 栈号（0或1）
 * @return 空返回OK，非空返回ERROR，栈号无效返回ERROR
 */
Status IsEmpty(DblStack s, int stackNum)
{
    if (stackNum != 0 && stackNum != 1)
        return 0; // 栈号无效
    if (stackNum == 0)
    {
        return (s.top[0] == -1) ? 1 : 0; // 0号栈空：top[0] = -1
    }
    else
    {
        return (s.top[1] == s.m) ? 1 : 0; // 1号栈空：top[1] = m
    }
}

/**
 * 判断双栈是否已满（两栈顶相遇）
 * @param s 双栈
 * @return 满返回OK，未满返回ERROR
 */
Status IsFull(DblStack s)
{
    // 0号栈顶的下一个位置等于1号栈顶时，无剩余空间
    return (s.top[0] + 1 == s.top[1]) ? 1 : 0;
}

/**
 * 进栈操作
 * @param s 双栈指针
 * @param stackNum 栈号（0或1）
 * @param e 待入栈元素
 * @return 成功返回OK，栈满/栈号无效返回ERROR
 */
Status Push(DblStack *s, int stackNum, SElemType e)
{
    if (stackNum != 0 && stackNum != 1)
        return 0; // 栈号无效
    if (IsFull(*s) == 1)
    {
        printf("双栈已满，无法进栈！\n");
        return 0;
    }

    if (stackNum == 0)
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

/**
 * 出栈操作
 * @param s 双栈指针
 * @param stackNum 栈号（0或1）
 * @param e 用于接收出栈元素的指针
 * @return 成功返回OK，栈空/栈号无效返回ERROR
 */
Status Pop(DblStack *s, int stackNum, SElemType *e)
{
    if (stackNum != 0 && stackNum != 1)
        return 0; // 栈号无效
    if (IsEmpty(*s, stackNum) == 1)
    {
        printf("栈%d为空，无法出栈！\n", stackNum);
        return 0;
    }

    if (stackNum == 0)
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

/**
 * 获取栈顶元素（不弹出）
 * @param s 双栈
 * @param stackNum 栈号（0或1）
 * @param e 用于接收栈顶元素的指针
 * @return 成功返回OK，栈空/栈号无效返回ERROR
 */
Status GetTop(DblStack s, int stackNum, SElemType *e)
{
    if (stackNum != 0 && stackNum != 1)
        return 0; // 栈号无效
    if (IsEmpty(s, stackNum) == 1)
    {
        printf("栈%d为空，无栈顶元素！\n", stackNum);
        return 0;
    }

    if (stackNum == 0)
    {
        *e = s.V[s.top[0]]; // 0号栈顶元素
    }
    else
    {
        *e = s.V[s.top[1]]; // 1号栈顶元素
    }
    return 1;
}

/**
 * 测试函数：演示双栈基本操作
 */
void TestDblStack()
{
    DblStack s;
    int m = 5; // 双栈总容量为5
    SElemType e;

    // 初始化双栈
    if (InitDblStack(&s, m) != 1)
    {
        printf("双栈初始化失败！\n");
        return;
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
    DestroyDblStack(&s);
    printf("双栈销毁完成\n");
}

int main()
{
    TestDblStack();
    return 0;
}
