#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif
#include <stdio.h>
#include <stdlib.h>

// 二叉树节点定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

static void CreateBiTree(BiTree *T) {
    char ch;
    if (scanf(" %c", &ch) != 1) {
        *T = NULL;
        return;
    }
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T) {
            fprintf(stderr, "内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

static void PreOrderTraverse(BiTree T) {
    if (T) {
        putchar(T->data);
        putchar(' ');
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

static void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        putchar(T->data);
        putchar(' ');
        InOrderTraverse(T->rchild);
    }
}

static void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        putchar(T->data);
        putchar(' ');
    }
}

static void DestroyTree(BiTree T) {
    if (!T) return;
    DestroyTree(T->lchild);
    DestroyTree(T->rchild);
    free(T);
}

static void PrintMenu(void) {
    printf("\n--- 选择遍历方式 ---\n");
    printf("1. 先序遍历\n");
    printf("2. 中序遍历\n");
    printf("3. 后序遍历\n");
    printf("4. 退出\n");
    printf("请输入选择 (1-4): ");
}

int main() {
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    // 初始化二叉树
    BiTree T = NULL;
    int choice = 0;

    printf("=== 链式二叉树遍历系统 ===\n");
    printf("请输入先序扩展序列构建二叉树（# 表示空节点，例如 AB#C##D##）：\n");
    // 构建二叉树
    CreateBiTree(&T);

    // 主循环处理用户选择
    while (choice != 4)
    {
        PrintMenu();
        if (scanf("%d", &choice) != 1)
        {
            fprintf(stderr, "输入错误，程序结束。\n");
            break;
        }
        switch (choice)
        {
        case 1:
            // 先序遍历
            printf("先序遍历结果: ");
            PreOrderTraverse(T);
            putchar('\n');
            break;
        case 2:
            // 中序遍历
            printf("中序遍历结果: ");
            InOrderTraverse(T);
            putchar('\n');
            break;
        case 3:
            // 后序遍历
            printf("后序遍历结果: ");
            PostOrderTraverse(T);
            putchar('\n');
            break;
        case 4:
            printf("程序已退出。\n");
            break;
        default:
            printf("无效输入，请输入 1~4 之间的数字！\n");
        }
    }

    // 销毁二叉树
    DestroyTree(T);

    return 0;  
}