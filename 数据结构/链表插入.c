#include <stdio.h>
#include <stdlib.h>

/*代码说明：
1.initList函数：现在只创建一个空节点，而不是直接插入所有元素。
2.main函数：在初始化链表后，逐个插入元素。
3.createNode函数：创建新节点  时，如果内存分配失败，会打印错误信息并退出程序。
4.insertAtHead函数：在链表头部插入新节点。
5.printList函数：打印链表中的所有元素。
6.freeList函数：释放链表占用的内存。
这样修改后，初始化函数只创建一个空节点，然后在主函数中逐个插入元素，最终实现链表的建立。
*/
/*在函数 insertAtHead(struct ListNode** head, int value) 中，参数 head 是一个指向 struct ListNode* 类型的指针的指针。这意味着函数可以直接修改指针 head 所指向的值。head 指向链表的头节点指针，通过传递 head 的地址，可以在函数内部更新头节点指针，使其指向新插入的节点。
这样做的好处是，可以在函数内部创建一个新的节点，并将其设置为链表的新头节点，然后更新外部传入的头节点指针，以确保它指向新的头节点。这是在不返回任何值的情况下修改链表头节点的一种常用方法。
例如，当调用 insertAtHead(&head, values[i]); 时，实际上是传递了 head 指针的地址给 insertAtHead 函数。在函数内部，可以创建一个新节点，并更新 *head（即 head 指针所指向的值）为这个新节点，从而在链表的头部插入新节点。
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
    // 初始化节点
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入新节点的函数
void insertAtHead(struct ListNode **head, int value)
{
    // 创建新节点并将其插入到链表头部
    struct ListNode *newNode = createNode(value);
    // 新节点的next指向当前的头节点
    newNode->next = *head;
    // 更新头节点为新节点
    *head = newNode;
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

int main()
{
    int values[] = {5, 4, 3, 2, 1};                // 初始值数组
    int size = sizeof(values) / sizeof(values[0]); // 数组大小

    // 初始化链表（现在直接初始化为NULL）
    struct ListNode *head = NULL;

    // 逐个插入元素到链表头部
    for (int i = 0; i < size; i++)
    {
        insertAtHead(&head, values[i]);
    }

    // 打印链表
    printList(head); // 输出应该是：1 2 3 4 5

    // 释放链表占用的内存
    freeList(head);

    return 0;
}
