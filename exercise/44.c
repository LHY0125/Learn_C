#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#endif

// 邻接矩阵存储图
typedef struct
{
    int vexnum;
    int **arcs;
} AMGraphStruct;
typedef AMGraphStruct *AMGraph;

// 定义最大顶点数和最大边权值
#define MaxInt 99999   // 最大边权值，用于初始化距离数组
#define MAXN 1005      // 最大顶点数
static bool S[MAXN];   // S[i]为true表示顶点i已加入集合S，否则未加入
static int D[MAXN];    // D[i]为v0到顶点i的当前最短路径长度
static int Path[MAXN]; // Path[i]为v0到顶点i的最短路径上的前驱顶点

// Dijkstra算法求最短路径
void ShortestPath_DIJ(AMGraph G, int v0)
{
    // 初始化
    int n, i, v, w; // n为顶点数，i为循环变量，v为当前顶点，w为邻接顶点
    int min;
    n = G->vexnum;
    for (v = 0; v < n; ++v)
    {
        S[v] = false;
        D[v] = G->arcs[v0][v];
        if (D[v] < MaxInt)
        {
            Path[v] = v0;
        }
        else
        {
            Path[v] = -1;
        }
    }
    S[v0] = true;
    D[v0] = 0;

    // 主循环，每次求得v0到某个顶点的最短路径，并将该顶点加入集合S
    for (i = 1; i < n; ++i)
    {
        // 在V-S中选择距离v0最近的顶点u
        min = MaxInt;
        for (w = 0; w < n; ++w)
        {
            if (!S[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        }
        S[v] = true;

        // 修改当前最短路径及距离
        for (w = 0; w < n; ++w)
        {
            if (!S[w] && (D[v] + G->arcs[v][w] < D[w]))
            {
                D[w] = D[v] + G->arcs[v][w];
                Path[w] = v;
            }
        }
    }
}

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // 输入顶点数和边数
    printf("请输入顶点数n和边数m：");
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    // 初始化邻接矩阵
    AMGraph g = (AMGraph)malloc(sizeof(*g));
    g->vexnum = n;
    g->arcs = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        g->arcs[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; ++j)
        {
            g->arcs[i][j] = (i == j) ? 0 : MaxInt;
        }
    }

    // 输入边信息
    for (int i = 0; i < m; ++i)
    {
        printf("请输入第%d条边的顶点x、y和边权z：", i + 1);
        int x, y, z;
        if (scanf("%d %d %d", &x, &y, &z) != 3)
        {
            return 0;
        }
        if (x >= 1 && x <= n && y >= 1 && y <= n)
        {
            if (z < g->arcs[x - 1][y - 1])
            {
                g->arcs[x - 1][y - 1] = z;
            }
        }
    }

    // 调用Dijkstra算法
    ShortestPath_DIJ(g, 0);
    if (D[n - 1] >= MaxInt)
    {
        printf("从顶点0到顶点%d不存在路径\n", n - 1);
    }
    else
    {
        printf("从顶点0到顶点%d的最短路径长度为：%d\n", n - 1, D[n - 1]);
    }

    // 释放内存
    for (int i = 0; i < n; ++i)
    {
        free(g->arcs[i]);
    }
    free(g->arcs);
    free(g);

    return 0;
}