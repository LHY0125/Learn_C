#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

#define MAX_SIZE 1000

// 栈结构用于存储数字
typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// 入栈
void push(Stack *s, int value)
{
    if (s->top < MAX_SIZE - 1)
    {
        s->data[++s->top] = value;
    }
}

// 出栈
int pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top--];
    }
    return 0;
}

// 获取栈顶元素
int peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }
    return 0;
}

// 判断运算符优先级
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 执行运算
int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

// 计算表达式
int evaluateExpression(char *expression)
{
    Stack numbers;
    Stack operators;
    initStack(&numbers);
    initStack(&operators);

    int len = strlen(expression);

    for (int i = 0; i < len; i++)
    {
        // 跳过空格
        if (expression[i] == ' ')
        {
            continue;
        }

        // 如果是数字
        if (isdigit(expression[i]))
        {
            int num = 0;
            // 读取完整的数字
            while (i < len && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // 回退一位，因为for循环会自动增加
            push(&numbers, num);
        }
        // 如果是运算符
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/')
        {

            // 处理运算符优先级
            while (!isEmpty(&operators) &&
                   precedence((char)peek(&operators)) >= precedence(expression[i]))
            {
                int b = pop(&numbers);
                int a = pop(&numbers);
                char op = (char)pop(&operators);
                push(&numbers, calculate(a, b, op));
            }
            push(&operators, expression[i]);
        }
    }

    // 处理剩余的运算符
    while (!isEmpty(&operators))
    {
        int b = pop(&numbers);
        int a = pop(&numbers);
        char op = (char)pop(&operators);
        push(&numbers, calculate(a, b, op));
    }

    return pop(&numbers);
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

    char expression[MAX_SIZE];

    // 读取表达式
    if (fgets(expression, sizeof(expression), stdin) != NULL)
    {
        // 去除换行符
        int len = strlen(expression);
        if (len > 0 && expression[len - 1] == '\n')
        {
            expression[len - 1] = '\0';
        }

        // 计算并输出结果
        int result = evaluateExpression(expression);
        printf("%d\n", result);
    }

    return 0;
}