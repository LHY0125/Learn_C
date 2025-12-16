#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 定义双向链表节点结构体
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// 定义双向链表结构体
struct DoubleList
{
    struct Node *head;
    struct Node *tail;
};

// 初始化双向链表
void initDoubleList(struct DoubleList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

// 获取双向链表长度
int getListLength(struct DoubleList *list)
{
    int length = 0;
    struct Node *current = list->head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

// 向双向链表头部添加节点
void addNodeToHead(struct DoubleList *list, int data)
{
    // 分配新节点内存
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    // 如果链表为空,则新节点同时是头节点和尾节点
    if (list->head == NULL)
    {
        list->tail = newNode;
    }
    else
    {
        list->head->prev = newNode;
    }

    // 更新头节点为新节点
    list->head = newNode;
}

// 向双向链表尾部添加节点
void addNodeToTail(struct DoubleList *list, int data)
{
    // 分配新节点内存
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = list->tail;
    newNode->next = NULL;

    // 如果链表为空,则新节点同时是头节点和尾节点
    if (list->tail == NULL)
    {
        list->head = newNode;
    }
    else
    {
        list->tail->next = newNode;
    }

    // 更新尾节点为新节点
    list->tail = newNode;
}

// 在指定位置插入节点
void insertNode(struct DoubleList *list, int data, int position)
{
    // 分配新节点内存
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // 如果插入位置为0,则在头部插入
    if (position == 0)
    {
        addNodeToHead(list, data);
    }
    // 如果插入位置大于等于链表长度,则在尾部插入
    else if (position >= getListLength(list))
    {
        addNodeToTail(list, data);
    }

    // 否则,在指定位置插入
    else
    {
        // 首先遍历到指定位置
        struct Node *current = list->head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }

        // 然后插入到指定位置
        newNode->prev = current->prev;
        newNode->next = current;

        // 更新当前节点的前一个节点的next指针
        current->prev->next = newNode;

        // 更新当前节点的前指针为新节点
        current->prev = newNode;
    }
}

// 删除指定位置的节点
int delectNode(struct DoubleList *list, int position)
{
    // 如果删除位置为0,则删除头节点
    if (position == 0)
    {
        // 如果链表只有一个节点,则删除后链表为空
        if (list->head == list->tail)
        {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else
        {
            // 更新头节点为下一个节点
            list->head = list->head->next;
            // 释放旧头节点内存,更新新头节点的prev指针为NULL
            free(list->head->prev);
            list->head->prev = NULL;
        }
        return 1;
    }
    // 如果删除位置大于等于链表长度,则删除尾节点
    else if (position >= getListLength(list))
    {
        // 更新尾节点为前一个节点
        list->tail = list->tail->prev;
        // 释放旧尾节点内存,更新新尾节点的next指针为NULL
        free(list->tail->next);
        list->tail->next = NULL;
        return 1;
    }
    // 如果删除位置在中间,则删除指定位置节点
    else
    {
        // 首先遍历到指定位置
        struct Node *current = list->head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        // 更新前一个节点的next指针为后一个节点
        current->prev->next = current->next;

        // 更新后一个节点的prev指针为前一个节点,更新当前节点的next指针为NULL
        current->next->prev = current->prev;

        free(current);
        
        return 1;
    }
}

// 修改指定位置节点的数据
int modifyNode(struct DoubleList *list, int data, int position)
{
    // 首先遍历到指定位置
    struct Node *current = list->head;
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }
    // 修改节点数据
    current->data = data;
    return 1;
}

// 查找指定数据的节点位置
int findNodePosition(struct DoubleList *list, int data)
{
    // 从头节点开始遍历
    struct Node *current = list->head;
    int position = 0;
    while (current != NULL)
    {
        // 如果找到匹配数据,则返回当前位置
        if (current->data == data)
        {
            return position;
        }
        // 否则,继续遍历下一个节点
        current = current->next;
        position++;
    }
    // 如果遍历完链表仍未找到匹配数据,则返回-1
    return -1;
}

// 查找指定位置的节点数据
int findNodeData(struct DoubleList *list, int position)
{
    // 首先遍历到指定位置
    struct Node *current = list->head;
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }
    // 返回当前节点数据
    return current->data;
}

// 打印链表所有节点数据
void printList(struct DoubleList *list)
{
    // 从头节点开始遍历
    struct Node *current = list->head;
    while (current != NULL)
    {
        // 打印当前节点数据
        printf("%d ", current->data);
        // 继续遍历下一个节点
        current = current->next;
    }
    // 打印换行符
    printf("\n");
}

int main()
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    // 初始化双端链表
    struct DoubleList list;
    initDoubleList(&list);

    // 输入节点数据
    printf("请输入初始节点数据的数量(默认在链表尾端插入):");
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("请输入第 %d 个节点数据:", i + 1);
        int data;
        scanf("%d", &data);
        addNodeToTail(&list, data);
    }

    while (1)
    {
        // 打印菜单
        printf("1. 插入节点\n");
        printf("2. 删除节点\n");
        printf("3. 修改节点\n");
        printf("4. 查找节点\n");
        printf("5. 打印链表\n");
        printf("0. 退出程序\n");
        printf("请输入操作选择:");
        int choice;
        scanf("%d", &choice);

        // 根据选择执行相应操作
        switch (choice)
        {
        case 1:
            printf("1. 在链表头插入节点\n");
            printf("2. 在链表尾插入节点\n");
            printf("3. 在指定位置插入节点\n");
            printf("请输入插入方式选择:");
            int addchoice;
            scanf("%d", &addchoice);

            printf("请输入要插入的数据:");
            int insertData;
            scanf("%d", &insertData);
            switch (addchoice)
            {
            case 1:
                addNodeToHead(&list, insertData);
                break;
            case 2:
                addNodeToTail(&list, insertData);
                break;
            case 3:
                printf("请输入要插入的位置:");
                int insertPosition;
                scanf("%d", &insertPosition);
                insertNode(&list, insertData, insertPosition);
                break;
            default:
                printf("无效选择,请重新输入\n");
                break;
            }
            break;
        case 2:
            printf("请输入要删除的位置:");
            int deletePosition;
            scanf("%d", &deletePosition);
            delectNode(&list, deletePosition);
            break;
        case 3:
            printf("请输入要修改的数据:");
            int modifyData;
            scanf("%d", &modifyData);
            printf("请输入要修改的位置:");
            int modifyPosition;
            scanf("%d", &modifyPosition);
            modifyNode(&list, modifyData, modifyPosition);
            break;
        case 4:
            printf("1. 查找指定数据的节点位置\n");
            printf("2. 查找指定位置的节点数据\n");
            printf("请输入查找方式选择:");
            int findchoice;
            scanf("%d", &findchoice);
            switch (findchoice)
            {
            case 1:
                printf("请输入要查找的数据:");
                int findData;
                scanf("%d", &findData);
                int position = findNodePosition(&list, findData);
                if (position != -1)
                {
                    printf("数据 %d 位于链表第 %d 个节点\n", findData, position);
                }
                else
                {
                    printf("链表中不存在数据 %d\n", findData);
                }
                break;
            case 2:
                printf("请输入要查找的位置:");
                int findPosition;
                scanf("%d", &findPosition);
                int data = findNodeData(&list, findPosition);
                if (data != -1)
                {
                    printf("链表第 %d 个节点的数据为 %d\n", findPosition, data);
                }
                else
                {
                    printf("链表中不存在第 %d 个节点\n", findPosition);
                }
                break;
            default:
                printf("无效选择,请重新输入\n");
                break;
            }
            break;
        case 5:
            printList(&list);
            break;
        case 0:
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择,请重新输入\n");
            break;
        }
    }
    
    return 0;
}