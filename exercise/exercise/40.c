#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 二叉树节点定义
struct BiTNode
{
    char data;              // 节点数据
    struct BiTNode *lchild; // 左子节点
    struct BiTNode *rchild; // 右子节点
};

typedef struct BiTNode *BiTree;

// 函数声明
void CreateBiTree(BiTree *T);     // 创建二叉树
void PreOrderTraverse(BiTree T);  // 先序遍历
void InOrderTraverse(BiTree T);   // 中序遍历
void PostOrderTraverse(BiTree T); // 后序遍历
void PrintMenu();                 // 打印菜单
void FreeTree(BiTree T);

int main()
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    BiTree T = NULL;
    int choice;

    printf("=== 链式二叉树遍历系统 (C语言版本) ===\n");
    printf("请输入先序扩展序列构建二叉树（# 表示空节点，例如 AB#C##D##）：\n");
    CreateBiTree(&T);

    do
    {
        PrintMenu();
        if (scanf("%d", &choice) != 1)
        {
            return 0;
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
            printf("程序已退出。\n");
            break;
        default:
            printf("无效输入，请输入 1~4 之间的数字！\n");
        }
    } while (choice != 4);

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
    if (T != NULL)
    {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历：左 -> 根 -> 右
void InOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历：左 -> 右 -> 根
void PostOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ", T->data);
    }
}

// 打印菜单
void PrintMenu()
{
    printf("\n--- 选择遍历方式 ---\n");
    printf("1. 先序遍历\n");
    printf("2. 中序遍历\n");
    printf("3. 后序遍历\n");
    printf("4. 退出\n");
    printf("请输入选择 (1-4): ");
}

void FreeTree(BiTree T)
{
    if (T)
    {
        FreeTree(T->lchild);
        FreeTree(T->rchild);
        free(T);
    }
}