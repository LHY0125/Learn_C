#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 简单环形队列
typedef struct
{
    int *buf; // 队列缓冲区
    int cap;  // 队列容量
    int head; // 队头指针
    int tail; // 队尾指针
    int len;  // 当前队列长度
} Queue;

// 初始化队列
static void Queue_init(Queue *q, int cap)
{
    q->buf = (int *)malloc(sizeof(int) * cap);
    q->cap = cap;
    q->head = 0;
    q->tail = 0;
    q->len = 0;
}

// 检查队列是否为空
static int Queue_empty(const Queue *q)
{
    return q->len == 0;
}

// 入队操作
static void Queue_push(Queue *q, int x)
{
    q->buf[q->tail] = x;
    q->tail = (q->tail + 1) % q->cap;
    q->len++;
}

// 弹出队列元素
static int Queue_pop(Queue *q)
{
    int x = q->buf[q->head];
    q->head = (q->head + 1) % q->cap;
    q->len--;
    return x;
}

// 释放队列内存（避免与标准库 free 冲突）
static void Queue_free(Queue *q)
{
    free(q->buf);
    q->buf = NULL;
    q->cap = 0;
    q->head = 0;
    q->tail = 0;
    q->len = 0;
}

int main(void)
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    int n, m;
    printf("请输入约瑟夫环的人数n和报数m: ");
    scanf("%d %d", &n, &m);
    if (n < 8 || n > 15 || m < 5 || m > 32767)
    {
        printf("输入错误，请重新输入!\n");
        printf("请重输入约瑟夫环的人数n和报数m: ");
        scanf("%d %d", &n, &m);
    }

    // 初始化队列
    Queue q;
    Queue_init(&q, n);

    // 入队操作
    for (int i = 0; i < n; i++)
    {
        Queue_push(&q, i + 1);
    }

    // 出队操作：模拟报数过程
    while (!Queue_empty(&q))
    {
        // 旋转 m-1 次：把队头移动到队尾（取模优化减少旋转次数）
        int k = (m - 1) % q.len;
        for (int t = 0; t < k; ++t)
        {
            Queue_push(&q, Queue_pop(&q));
        }
        int out = Queue_pop(&q);
        printf("%d ", out);
    }

    // 释放队列内存
    Queue_free(&q);
    return 0;
}