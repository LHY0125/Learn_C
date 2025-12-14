#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

// 图的邻接矩阵表示
typedef struct
{
    int n;
    int directed;
    int **mat;
} GraphMat;

// 图的邻接表边的表示
typedef struct Edge
{
    int to;
    struct Edge *next;
} Edge;

// 图的邻接表表示
typedef struct
{
    int n;
    int directed;
    Edge **head;
} GraphList;

// 创建邻接矩阵表示的图
GraphMat GraphMatCreate(int n, int directed)
{
    GraphMat g;
    g.n = n;
    g.directed = directed;
    g.mat = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        g.mat[i] = (int *)calloc((size_t)n, sizeof(int));
    }
    return g;
}

// 添加邻接矩阵表示的图的边
void GraphMatAddEdge(GraphMat *g, int u, int v)
{
    int n = g->n;
    if (u >= 1 && u <= n && v >= 1 && v <= n)
    {
        g->mat[u - 1][v - 1] = 1;
        if (!g->directed)
        {
            g->mat[v - 1][u - 1] = 1;
        }
    }
}

// 释放邻接矩阵表示的图
void GraphMatFree(GraphMat *g)
{
    if (g->mat)
    {
        for (int i = 0; i < g->n; ++i)
            free(g->mat[i]);
        free(g->mat);
        g->mat = NULL;
    }
}

// 创建邻接表表示的图
GraphList GraphListCreate(int n, int directed)
{
    GraphList g;
    g.n = n;
    g.directed = directed;
    g.head = (Edge **)calloc((size_t)n + 1, sizeof(Edge *));
    return g;
}

// 添加邻接表表示的图的边
void GraphListAddEdge(GraphList *g, int u, int v)
{
    int n = g->n;
    if (u >= 1 && u <= n && v >= 1 && v <= n)
    {
        Edge *e = (Edge *)malloc(sizeof(Edge));
        e->to = v;
        e->next = g->head[u];
        g->head[u] = e;
        if (!g->directed)
        {
            Edge *e2 = (Edge *)malloc(sizeof(Edge));
            e2->to = u;
            e2->next = g->head[v];
            g->head[v] = e2;
        }
    }
}

// 释放邻接表表示的图
void GraphListFree(GraphList *g)
{
    for (int i = 1; i <= g->n; ++i)
    {
        Edge *p = g->head[i];
        while (p)
        {
            Edge *nxt = p->next;
            free(p);
            p = nxt;
        }
    }
    free(g->head);
    g->head = NULL;
}

// 打印邻接矩阵表示的图
void PrintMatrix(const GraphMat *g)
{
    int n = g->n;
    printf("邻接矩阵:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j)
            {
                printf(" ");
            }  
            printf("%d", g->mat[i][j]);
        }
        printf("\n");
    }
}

// 打印邻接表表示的图
void PrintList(const GraphList *g)
{
    printf("邻接表:\n");
    for (int i = 1; i <= g->n; ++i)
    {
        printf("%d:", i);
        Edge *p = g->head[i];
        if (p)
        {
            printf(" ");
        }
        int first = 1;
        while (p)
        {
            if (!first)
            {
                printf(" ");
            }
            printf("%d", p->to);
            first = 0;
            p = p->next;
        }
        printf("\n");
    }
}

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // 图的顶点数、边数和是否有向
    int n, m, dir;
    printf("请输入图的顶点数、边数和是否有向(0:无向, 1:有向): ");
    if (scanf("%d %d %d", &n, &m, &dir) != 3)
    {
        printf("输入错误\n");
        return 0;
    }
    if (n <= 0 || m < 0 || (dir != 0 && dir != 1))
    {
        printf("输入错误\n");
        return 0;
    }

    // 创建邻接矩阵表示的图和邻接表表示的图
    GraphMat gm = GraphMatCreate(n, dir);
    GraphList gl = GraphListCreate(n, dir);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2)
        {
            printf("输入错误\n");
            break;
        }

        // 添加邻接矩阵表示的图的边和邻接表表示的图的边
        GraphMatAddEdge(&gm, u, v);
        GraphListAddEdge(&gl, u, v);
    }

    // 打印邻接矩阵表示的图和邻接表表示的图
    PrintMatrix(&gm);
    PrintList(&gl);

    // 释放邻接矩阵表示的图和邻接表表示的图 
    GraphMatFree(&gm);
    GraphListFree(&gl);

    return 0;
}