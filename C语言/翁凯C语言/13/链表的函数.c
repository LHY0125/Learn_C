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

// !链表
/*
    1.
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

    return 0;
}