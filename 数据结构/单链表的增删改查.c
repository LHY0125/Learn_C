#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

/**
 * @brief 将指令复制到PowerShell
 * gcc "数据结构\单链表的增删改查.c" -o 数据结构\output\单链表的增删改查.exe
  .\数据结构\output\单链表的增删改查.exe
 */

/*代码说明：
1.initList函数：现在只创建一个空节点，而不是直接插入所有元素。
2.main函数：在初始化链表后，逐个插入元素。
3.createNode函数：创建新节点  时，如果内存分配失败，会打印错误信息并退出程序。
4.insertAtHead函数：在链表头部插入新节点。
5.printList函数：打印链表中的所有元素。
6.freeList函数：释放链表占用的内存。
这样修改后，初始化函数只创建一个空节点，然后在主函数中逐个插入元素，最终实现链表的建立。
*/
/*在函数 insertAtHead(struct ListNode** head, int value) 中，参数 head 是一个指向 struct ListNode* 类型的指针的指针。
这意味着函数可以直接修改指针 head 所指向的值。
head 指向链表的头节点指针，通过传递 head 的地址，可以在函数内部更新头节点指针，使其指向新插入的节点。
这样做的好处是，可以在函数内部创建一个新的节点，并将其设置为链表的新头节点，然后更新外部传入的头节点指针，以确保它指向新的头节点。
这是在不返回任何值的情况下修改链表头节点的一种常用方法。
例如，当调用 insertAtHead(&head, values[i]); 时，实际上是传递了 head 指针的地址给 insertAtHead 函数。
在函数内部，可以创建一个新节点，并更新 *head（即 head 指针所指向的值）为这个新节点，从而在链表的头部插入新节点。
*/

// 定义链表节点结构体
struct ListNode
{
    int value;
    struct ListNode *next;
};

// 创建一个新节点的函数
struct ListNode *createNode(int value)
{
    // 为新节点分配内存
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL)
    {
        // 处理内存分配失败的情况
        printf("Memory allocation failed\n");
        exit(1);
    }
    // 初始化头节点
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入新节点的函数（头插法）
void insertAtHead(struct ListNode **head, int value)
{
    // 创建新节点并将其插入到链表头部
    struct ListNode *newNode = createNode(value);
    // 新节点的next指向当前的头节点
    newNode->next = *head;
    // 更新头节点为新节点
    *head = newNode;
}

// 在链表尾部插入新节点的函数（尾插法）
void insertAtEnd(struct ListNode **head, int value)
{
    // 创建新节点并将其插入到链表尾部
    struct ListNode *newNode = createNode(value);
    // 如果链表为空，新节点直接成为头节点
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // 否则，遍历到链表尾部
    struct ListNode *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    // 将新节点连接到链表尾部
    current->next = newNode;
}

// 删除第一个值为value的节点，返回是否删除成功
int deleteByValue(struct ListNode **head, int value)
{
    if (head == NULL || *head == NULL)
    {
        printf("链表为空，无法删除值为 %d 的节点\n", value);
        return 0;
    }

    struct ListNode *current = *head;
    struct ListNode *previous = NULL;
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("链表中不存在值为 %d 的节点\n", value);
        return 0;
    }
    if (previous == NULL)
    {
        *head = current->next;
    }
    else
    {
        previous->next = current->next;
    }
    free(current);
    return 1;
}

// 删除指定位置的节点（0 为头），返回是否删除成功
int deleteAtPosition(struct ListNode **head, int pos)
{
    if (head == NULL || *head == NULL || pos < 0)
        return 0;
    struct ListNode *current = *head;
    struct ListNode *previous = NULL;
    int idx = 0;
    while (current != NULL && idx < pos)
    {
        previous = current;
        current = current->next;
        idx++;
    }
    if (current == NULL)
        return 0;
    if (previous == NULL)
        *head = current->next;
    else
        previous->next = current->next;
    free(current);
    return 1;
}

// 打印链表
void printList(struct ListNode *head)
{
    // 遍历链表并打印每个节点的值
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// 释放链表占用的内存
void freeList(struct ListNode *head)
{
    // 遍历链表并释放每个节点的内存
    struct ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 初始化链表的函数，只创建一个空节点（但这里其实不需要空节点，因为头节点可以直接是数据节点）
struct ListNode *initList()
{
    // 原本这里创建了一个空节点，但根据后续操作，我们可以直接不创建空节点
    // 这里返回NULL作为初始的空链表头
    return NULL;
}

// 清理输入缓冲区中的残留字符
void deleteInput()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
    _mkdir("records");
#endif

    // 初始化空链表头
    struct ListNode *head = NULL;

    // 用户输入初始链表
    printf("=== 初始化链表 ===\n");
    printf("请输入初始链表的元素（输入负数结束）:\n");
    int value;
    while (1)
    {
        printf("输入元素值: ");
        if (scanf("%d", &value) != 1)
        {
            printf("输入无效，请输入整数。\n");
            deleteInput();
            continue;
        }
        if (value < 0)
        {
            printf("输入结束，初始链表创建完成。\n");
            break;
        }
        // 尾插
        insertAtEnd(&head, value);
    }

    // 显示初始链表
    if (head != NULL)
    {
        printf("初始链表: ");
        printList(head);
    }
    else
    {
        printf("初始链表为空。\n");
    }

    while (1)
    {
        // 打印菜单
        printf("\n=== 链表操作菜单 ===\n");
        printf("1. 头插\n");
        printf("2. 尾插\n");
        printf("3. 按值删除\n");
        printf("4. 按位置删除\n");
        printf("5. 打印链表\n");
        printf("6. 释放链表\n");
        printf("7. 退出\n");
        printf("请选择: ");

        int choice;
        if (scanf("%d", &choice) != 1)
        {
            printf("输入无效，请输入数字。\n");
            deleteInput();
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("输入要头插的值: ");
            if (scanf("%d", &value) != 1)
            {
                printf("输入无效。\n");
                deleteInput();
                break;
            }
            insertAtHead(&head, value);
            printList(head);
            break;
        }
        case 2:
        {
            int value;
            printf("输入要尾插的值: ");
            if (scanf("%d", &value) != 1)
            {
                printf("输入无效。\n");
                deleteInput();
                break;
            }
            insertAtEnd(&head, value);
            printList(head);
            break;
        }
        case 3:
        {
            int value;
            printf("输入要删除的值: ");
            if (scanf("%d", &value) != 1)
            {
                printf("输入无效。\n");
                deleteInput();
                break;
            }
            int ok = deleteByValue(&head, value);
            (void)ok; // 删除函数内部已打印未找到提示
            printList(head);
            break;
        }
        case 4:
        {
            int pos;
            printf("输入要删除的位置(0为头): ");
            if (scanf("%d", &pos) != 1)
            {
                printf("输入无效。\n");
                deleteInput();
                break;
            }
            int ok = deleteAtPosition(&head, pos);
            if (!ok)
            {
                printf("位置无效或链表为空\n");
            }
            printList(head);
            break;
        }
        case 5:
            printf("当前链表: ");
            printList(head);
            break;
        case 6:
            freeList(head);
            head = NULL;
            printf("链表已释放\n");
            break;
        case 7:
            printf("程序结束\n");
            freeList(head);  // 退出前释放链表内存
            return 0;
        default:
            printf("无效选项，请输入 1-7\n");
        }
    }

    // 程序结束释放链表内存
    freeList(head);

    return 0;
}