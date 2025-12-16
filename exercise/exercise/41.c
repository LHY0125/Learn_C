#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 链式二叉树节点结构
struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
};

// 二叉树指针类型定义
typedef struct BiTNode *BiTree;

// 函数声明
void CreateBiTree(BiTree *T);       // 创建二叉树
void PreOrderTraverse(BiTree T);    // 先序遍历
void InOrderTraverse(BiTree T);     // 中序遍历
void PostOrderTraverse(BiTree T);   // 后序遍历
void LevelOrderTraverse(BiTree T);  // 层次遍历
int MaxWidth(BiTree T);             // 计算最大宽度
void PrintMenu();                   // 打印菜单
void FreeTree(BiTree T);            // 释放二叉树内存

int main(void)
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    BiTree T = NULL;
    int choice;

    printf("=== 链式二叉树遍历系统 (C语言非递归) ===\n");
    printf("请输入先序扩展序列构建二叉树（# 表示空节点，例如 AB#C##D##）：\n");
    CreateBiTree(&T);

    do
    {
        PrintMenu();
        if (scanf("%d", &choice) != 1)
        {
            printf("无效输入，请输入1~6之间的数字！\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("先序遍历结果: ");
            PreOrderTraverse(T);
            printf("\n");
            break;
        case 2:
            printf("中序遍历结果: ");
            InOrderTraverse(T);
            printf("\n");
            break;
        case 3:
            printf("后序遍历结果: ");
            PostOrderTraverse(T);
            printf("\n");
            break;
        case 4:
            printf("层次遍历结果: ");
            LevelOrderTraverse(T);
            printf("\n");
            break;
        case 5:
            printf("程序已退出。\n");
            break;
        case 6:
            printf("最大宽度: %d\n", MaxWidth(T));
            break;
        default:
            printf("无效输入，请输入 1~6 之间的数字！\n");
        }
    } while (choice != 5);

    FreeTree(T);
    return 0;
}

// 创建二叉树（先序扩展输入）
void CreateBiTree(BiTree *T)
{
    char ch;
    if (scanf(" %c", &ch) != 1)
    {
        *T = NULL;
        return;
    }

    if (ch == '#')
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (struct BiTNode *)malloc(sizeof(struct BiTNode));
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

// 先序遍历：根 -> 左 -> 右
void PreOrderTraverse(BiTree T)
{
    if (!T)
    {
        return;
    }
    // 栈初始化,用栈来显性表示递归时的函数调用
    int cap = 128, top = 0;
    BiTree *st = (BiTree *)malloc(sizeof(BiTree) * cap);
    st[top++] = T;

    while (top)
    {
        BiTree p = st[--top];
        printf("%c ", p->data);
        if (p->rchild)
        {
            if (top >= cap)
            {
                cap *= 2;
                st = (BiTree *)realloc(st, sizeof(BiTree) * cap);
            }
            st[top++] = p->rchild;
        }
        if (p->lchild)
        {
            if (top >= cap)
            {
                cap *= 2;
                st = (BiTree *)realloc(st, sizeof(BiTree) * cap);
            }
            st[top++] = p->lchild;
        }
    }
    free(st);
}

// 中序遍历：左 -> 根 -> 右
void InOrderTraverse(BiTree T)
{
    int cap = 128, top = 0;
    BiTree *st = (BiTree *)malloc(sizeof(BiTree) * cap);
    BiTree cur = T;
    while (cur || top)
    {
        while (cur)
        {
            if (top >= cap)
            {
                cap *= 2;
                st = (BiTree *)realloc(st, sizeof(BiTree) * cap);
            }
            st[top++] = cur;
            cur = cur->lchild;
        }
        BiTree p = st[--top];
        printf("%c ", p->data);
        cur = p->rchild;
    }
    free(st);
}

// 后序遍历：左 -> 右 -> 根
void PostOrderTraverse(BiTree T)
{
    int cap = 128, top = 0;
    BiTree *st = (BiTree *)malloc(sizeof(BiTree) * cap);
    BiTree cur = T, last = NULL;
    while (cur || top)
    {
        while (cur)
        {
            if (top >= cap)
            {
                cap *= 2;
                st = (BiTree *)realloc(st, sizeof(BiTree) * cap);
            }
            st[top++] = cur;
            cur = cur->lchild;
        }
        BiTree p = st[top - 1];
        if (p->rchild && last != p->rchild)
        {
            cur = p->rchild;
        }
        else
        {
            printf("%c ", p->data);
            last = p;
            --top;
        }
    }
    free(st);
}

// 层次遍历：按层从左到右遍历
void LevelOrderTraverse(BiTree T)
{
    if (!T)
    {
        return;
    }
    int cap = 128;
    BiTree *q = (BiTree *)malloc(sizeof(BiTree) * cap);
    int head = 0, tail = 0;
    q[tail++] = T;
    while (head < tail)
    {
        BiTree p = q[head++];
        printf("%c ", p->data);
        if (p->lchild)
        {
            if (tail >= cap)
            {
                cap *= 2;
                q = (BiTree *)realloc(q, sizeof(BiTree) * cap);
            }
            q[tail++] = p->lchild;
        }
        if (p->rchild)
        {
            if (tail >= cap)
            {
                cap *= 2;
                q = (BiTree *)realloc(q, sizeof(BiTree) * cap);
            }
            q[tail++] = p->rchild;
        }
    }
    free(q);
}

// 计算二叉树的最大宽度
int MaxWidth(BiTree T)
{
    if (!T) return 0;
    int cap = 128;
    BiTree *q = (BiTree *)malloc(sizeof(BiTree) * cap);
    int head = 0, tail = 0;
    int maxw = 0;
    q[tail++] = T;
    while (head < tail)
    {
        int level_size = tail - head;
        if (level_size > maxw) maxw = level_size;
        for (int i = 0; i < level_size; ++i)
        {
            BiTree p = q[head++];
            if (p->lchild)
            {
                if (tail >= cap)
                {
                    cap *= 2;
                    q = (BiTree *)realloc(q, sizeof(BiTree) * cap);
                }
                q[tail++] = p->lchild;
            }
            if (p->rchild)
            {
                if (tail >= cap)
                {
                    cap *= 2;
                    q = (BiTree *)realloc(q, sizeof(BiTree) * cap);
                }
                q[tail++] = p->rchild;
            }
        }
    }
    free(q);
    return maxw;
}

// 打印菜单
void PrintMenu(void)
{
    printf("\n--- 选择遍历方式(非递归) ---\n");
    printf("1. 先序遍历\n");
    printf("2. 中序遍历\n");
    printf("3. 后序遍历\n");
    printf("4. 层次遍历\n");
    printf("5. 退出\n");
    printf("6. 最大宽度\n");
    printf("请输入选择 (1-6): ");
}

// 释放二叉树内存
void FreeTree(BiTree T)
{
    if (T)
    {
        FreeTree(T->lchild);
        FreeTree(T->rchild);
        free(T);
    }
}