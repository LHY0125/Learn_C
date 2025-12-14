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
    int *buf;
    int cap;
    int head;
    int tail;
    int len;
} Queue;

static void q_init(Queue *q, int cap)
{
    q->buf = (int *)malloc(sizeof(int) * cap);
    q->cap = cap;
    q->head = 0;
    q->tail = 0;
    q->len = 0;
}

static int q_empty(const Queue *q) { return q->len == 0; }

static void q_push(Queue *q, int x)
{
    q->buf[q->tail] = x;
    q->tail = (q->tail + 1) % q->cap;
    q->len++;
}

static int q_pop(Queue *q)
{
    int x = q->buf[q->head];
    q->head = (q->head + 1) % q->cap;
    q->len--;
    return x;
}

static void q_free(Queue *q)
{
    free(q->buf);
    q->buf = NULL;
    q->cap = q->head = q->tail = q->len = 0;
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
    if (scanf("%d %d", &n, &m) != 2)
        return 0;
    if (n <= 0 || m <= 0)
        return 0;

    Queue q;
    q_init(&q, n);
    for (int i = 1; i <= n; ++i)
        q_push(&q, i);

    while (!q_empty(&q))
    {
        // 旋转 m-1 次：把队头移动到队尾（取模优化减少旋转次数）
        int k = (m - 1) % q.len;
        for (int t = 0; t < k; ++t)
        {
            q_push(&q, q_pop(&q));
        }
        int out = q_pop(&q);
        printf("%d\n", out);
    }

    q_free(&q);
    return 0;
}