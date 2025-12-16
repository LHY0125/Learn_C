#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 栈结构定义
typedef struct
{
    long long *data;
    int top;
    int capacity;
} Stack;

// 栈初始化
void stack_init(Stack *st, int initial_capacity)
{
    int cap = initial_capacity > 0 ? initial_capacity : 2;

    st->data = (long long *)malloc(sizeof(long long) * cap);
    st->top = 0;
    st->capacity = cap;
}

// 栈释放
void stack_free(Stack *st)
{
    free(st->data);
    st->data = NULL;
    st->top = 0;
    st->capacity = 0;
}

// 栈是否为空
int stack_empty(const Stack *st)
{
    return st->top == 0;
}

// 栈压栈
void stack_push(Stack *st, long long v)
{
    if (st->top >= st->capacity)
    {
        int new_cap = st->capacity ? st->capacity * 2 : 2;
        long long *nd = (long long *)realloc(st->data, sizeof(long long) * new_cap);
        if (!nd)
        {
            free(st->data);
            exit(0);
        }
        st->data = nd;
        st->capacity = new_cap;
    }
    st->data[st->top++] = v;
}

// 栈弹栈
long long stack_pop(Stack *st)
{
    if (st->top == 0)
    {
        return 0;
    }
    return st->data[--st->top];
}

// 栈顶元素
long long stack_top(const Stack *st)
{
    if (st->top == 0)
    {
        return 0;
    }
    return st->data[st->top - 1];
}

int main(void)
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    // 动态读取一行表达式
    size_t cap = 1024, len = 0;
    char *s = (char *)malloc(cap);
    if (!s)
        return 0;
    int ch;
    // 读取表达式
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (len + 1 >= cap)
        {
            // 容量不足时，倍增扩容
            cap <<= 1;
            char *ns = (char *)realloc(s, cap);
            if (!ns)
            {
                free(s);
                return 0;
            }
            s = ns;
        }
        // 逐字符写入
        s[len++] = (char)ch;
    }
    s[len] = '\0';
    if (len == 0)
    {
        free(s);
        return 0;
    }

    Stack st;
    stack_init(&st, (int)len + 1);

    long long num = 0;
    // 记录最近的运算符，初始为加号
    char op = '+';

    for (size_t i = 0; i < len; ++i)
    {
        char c = s[i];
        // 跳过空格字符
        if (isspace((unsigned char)c))
            continue;

        if (isdigit((unsigned char)c))
        {
            // 累积多位数字
            num = num * 10 + (c - '0');
        }
        else
        {
            // 根据“前一个”运算符 op 处理当前数字 num；
            // 乘除即时计算以确保高于加减的优先级
            switch (op)
            {
            case '+':
                stack_push(&st, num);
                break;
            case '-':
                stack_push(&st, -num);
                break;
            case '*':
            {
                long long a = stack_pop(&st);
                stack_push(&st, a * num);
                break;
            }
            case '/':
            {
                long long a = stack_pop(&st);
                stack_push(&st, a / num);
                break;
            }
            default:
                break;
            }
            // 更新待应用的运算符为当前位置字符
            op = c;
            // 重置当前数字，继续解析
            num = 0;
        }
    }

    // 处理末尾累积数字（循环结束后最后一个数尚未被处理）
    switch (op)
    {
    case '+':
        stack_push(&st, num);
        break;
    case '-':
        stack_push(&st, -num);
        break;
    case '*':
    {
        long long a = stack_pop(&st);
        stack_push(&st, a * num);
        break;
    }
    case '/':
    {
        long long a = stack_pop(&st);
        // C 的整数除法向零截断
        stack_push(&st, a / num);
        break;
    }
    default:
        break;
    }

    long long ans = 0;
    // 栈中为已应用乘除的加减项，累加得到结果
    while (!stack_empty(&st))
        ans += stack_pop(&st);

    printf("%lld\n", ans);

    stack_free(&st);
    free(s);
    return 0;
}