#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// !链表的清除
/*
    1. 清除链表中的所有节点
    2. 释放链表占用的内存
    2.1 使用malloc申请的动态内存需要释放
    2.2 用malloc申请的内存，即使没有赋值，也会被赋值一个特定的值
        赋值就是使用，所以没必要为这种内存清空赋值
*/

typedef struct _node{
    int value;
    struct _node *next;
} Node;

typedef struct _list{
    Node *head;
    Node *tail;
} List;

void add(List* pList, int value)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->value = value;
    p->next = NULL;
    // 将节点插入链表
    Node *last = pList->head;
    if (last!=NULL)
    {
        while (last->next!=NULL)
        {
            last = last->next;
        }
        // attach
        last->next = p;
    }
    else
    {
        pList->head = p;
    }
}

void print(List* pList)
{
    Node *p;
    for (p=pList->head; p; p=p->next)
    {
        printf("%d\t", p->value);
    }
    printf("\n");
}

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    List list;
    list.head = NULL;
    list.tail = NULL;
    int number;
    do {
        printf("请输入一个整数：");
        scanf("%d", &number);
        if (number!=-1)
        {
            
            add(&list, number);
            
        }
    } while (number!=-1);
    print(&list);

    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for (p=list.head; p; p=p->next)
    {
        if (p->value==number)
        {
            printf("找到！\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("未找到！\n");
    }

    Node *q;
    for (q = NULL, p = list.head; p; q=p, p = p->next)
    {
        if (p->value == number)
        {
            if (q==NULL)
            {
                list.head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            free(p);
            printf("删除成功！\n");
            
            break;
        }
    }

    for (p=list.head; p; p=p)
    {
        q=p->next;
        free(p);
    }

    return 0;
}