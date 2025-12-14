#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10002

// 栈结构
typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

// 判断栈是否已满
bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// 入栈
bool push(Stack *s, char item)
{
    if (isFull(s))
    {
        return false;
    }
    s->data[++s->top] = item;
    return true;
}

// 出栈
bool pop(Stack *s, char *item)
{
    if (isEmpty(s))
    {
        return false;
    }
    *item = s->data[s->top--];
    return true;
}

// 判断字符是否为左括号
bool isLeftBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

// 判断字符是否为右括号
bool isRightBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

// 判断左右括号是否匹配
bool isMatching(char left, char right)
{
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

// 括号匹配验证函数
bool isValidBrackets(char *s)
{
    Stack stack;
    initStack(&stack);

    int len = strlen(s);

    // 空字符串返回true
    if (len == 0)
    {
        return true;
    }

    for (int i = 0; i < len; i++)
    {
        char current = s[i];

        // 如果是左括号，入栈
        if (isLeftBracket(current))
        {
            if (!push(&stack, current))
            {
                // 栈满，返回false
                return false;
            }
        }
        // 如果是右括号，检查匹配
        else if (isRightBracket(current))
        {
            // 栈为空，说明没有对应的左括号
            if (isEmpty(&stack))
            {
                return false;
            }

            char top;
            pop(&stack, &top);

            // 检查是否匹配
            if (!isMatching(top, current))
            {
                return false;
            }
        }
        // 根据题目描述，输入只包含括号字符，不应该有其他字符
    }

    // 最后栈应该为空，表示所有括号都已匹配
    return isEmpty(&stack);
}

int main()
{
    char s[MAX_SIZE];

    // 读取输入字符串
    if (fgets(s, sizeof(s), stdin) != NULL)
    {
        // 去除换行符
        int len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
        {
            s[len - 1] = '\0';
        }

        // 验证括号匹配并输出结果
        if (isValidBrackets(s))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    else
    {
        // 如果读取失败，输出false
        printf("false\n");
    }

    return 0;
}