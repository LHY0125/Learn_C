#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief 将指令复制到powershell
 * gcc "课上代码练习\五子棋\五子棋.c" -o output/五子棋.exe
 * @brief 将指令复制到powershell
 * .\output\五子棋.exe
 */

// !宏定义
#define MAX_BOARD_SIZE 25                           //* 最大支持棋盘尺寸
int BOARD_SIZE = 15;                                //* 实际使用的棋盘尺寸(默认15)
#define PLAYER 1                                    //* 玩家棋子标识符
#define AI 2                                        //* AI棋子标识符
#define EMPTY 0                                     //* 空位置标识符
#define MAX_STEPS (MAX_BOARD_SIZE * MAX_BOARD_SIZE) //* 最大步数（棋盘总格数）

// !全局变量
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};               //* 棋盘状态存储数组(默认棋盘全空为0)
const int direction[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}}; //* 四个方向：向下、向右、右下、左下

// !落子步骤结构体
typedef struct  // 落子结构体
{
    int player; // 落子方标识
    int x, y;   // 坐标位置
} Step;

// !方向信息结构体
typedef struct
{
    int continuous_chess; // 连续棋子数量
    bool check_start;     // 序列起点方向是否开放（空位）
    bool check_end;       // 序列终点方向是否开放（空位）
} DirInfo;

Step steps[MAX_STEPS]; // 存储所有落子步骤

int step_count = 0; // 当前步数计数器

// !初始化棋盘：清空棋盘状态和步数记录
void empty_board();

// !打印当前棋盘状态
void print_board();

// !检查位置是否有效（在棋盘范围内且为空位）
bool have_space(int x, int y);

// !玩家落子操作
bool player_move(int x, int y);

// !计算特定方向上连续同色棋子数量
DirInfo count_specific_direction(int x, int y, int dx, int dy, int player);

// !检查特定位置落子后是否获胜
bool check_win(int x, int y, int player);

// !评估特定位置对当前玩家的价值
int evaluate_pos(int x, int y, int player);

// !AI落子算法
void ai_move();

// !复盘游戏过程
void review_process();

// !主函数：游戏流程控制
int main()
{
    // 初始化阶段：获取棋盘尺寸
    printf("===== 五子棋人机对战 =====\n");
    printf("通常棋盘大小分为休闲棋盘(13X13)、标准棋盘(15X15)和特殊棋盘(19X19)\n");
    printf("请输入棋盘大小(5~%d)(默认为标准棋盘):", MAX_BOARD_SIZE);
    scanf("%d", &BOARD_SIZE);
    if (BOARD_SIZE < 5 || BOARD_SIZE > MAX_BOARD_SIZE)
    {
        BOARD_SIZE = 15;
        printf("输入无效，使用默认标准棋盘15X15\n");
    }

    empty_board();
    printf("===== 五子棋人机对战(%dX%d棋盘) =====", BOARD_SIZE, BOARD_SIZE);
    print_board();

    // 游戏主循环
    while (1)
    {
        // 玩家回合
        int x, y;
        printf("\n请输入落子坐标(行 列，1~%d):", BOARD_SIZE);
        scanf("%d %d", &x, &y);
        // 转换为0-BOARD_SIZE索引(转为棋盘的坐标)
        x--;
        y--;

        // 验证并执行玩家移动
        if (!player_move(x, y))
        {
            printf("坐标无效！请重新输入。\n");
            continue;
        }
        print_board();

        // 检查玩家是否获胜
        if (check_win(x, y, PLAYER))
        {
            printf("\n玩家获胜！\n");
            review_process();
            break;
        }

        // AI回合
        printf("\nAI思考中...\n");
        ai_move();
        print_board();

        // 检查AI是否获胜
        Step last_step = steps[step_count - 1];
        if (check_win(last_step.x, last_step.y, AI))
        {
            printf("\nAI获胜！\n");
            review_process();
            break;
        }

        // 检查平局（棋盘已满）
        if (step_count == BOARD_SIZE * BOARD_SIZE)
        {
            printf("\n平局！\n");
            review_process();
            break;
        }
    }

    return 0;
}

// !初始化棋盘：清空棋盘状态和步数记录
void empty_board()
{
    // 初始化棋盘状态
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    step_count = 0;
}

// !打印当前棋盘状态
void print_board()
{
    // 打印列号（1-BOARD_SIZE显示）
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d", i + 1);
        if (i + 1 == 9) // 处理两位数列号的对齐
            printf(" ");
    }
    printf("\n");

    // 打印每行棋盘内容
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d ", i + 1); // 打印行号（1-BOARD_SIZE）
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == PLAYER)
                printf("x "); // 玩家棋子
            else if (board[i][j] == AI)
                printf("○ "); // AI棋子
            else
                printf("· "); // 空位
        }
        printf("\n");
    }
}

// !检查位置是否有效（在棋盘范围内且为空位）
bool have_space(int x, int y)
{
    /* 检查位置是否有效且为空位 */
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY);
}

// !玩家落子操作
bool player_move(int x, int y)
{
    if (!have_space(x, y))
    {
        return false; // 位置无效返回失败
    }

    board[x][y] = PLAYER;                       // 更新棋盘状态
    steps[step_count++] = (Step){PLAYER, x, y}; // 记录步骤
    return true;
}

// !计算特定方向上连续同色棋子数量
DirInfo count_specific_direction(int x, int y, int dx, int dy, int player)
{
    DirInfo info;
    info.continuous_chess = 1; // 包含当前位置
    info.check_start = false;
    info.check_end = false;

    // 检查正方向（dx, dy）
    int nx = x + dx, ny = y + dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++;
        nx += dx;
        ny += dy;
    }
    // 判断正方向端点是否开放
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
    {
        if (board[nx][ny] == EMPTY)
        {
            info.check_end = true;
        }
    }

    // 检查反方向（-dx, -dy）
    nx = x - dx, ny = y - dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++;
        nx -= dx;
        ny -= dy;
    }
    // 判断反方向端点是否开放
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
    {
        if (board[nx][ny] == EMPTY)
        {
            info.check_start = true;
        }
    }

    return info;
}

// !检查特定位置落子后是否获胜
bool check_win(int x, int y, int player)
{
    for (int i = 0; i < 4; i++)
    {
        DirInfo info = count_specific_direction(x, y, direction[i][0], direction[i][1], player);
        if (info.continuous_chess >= 5)
            return true;
    }
    return false;
}

// !评估特定位置对当前玩家的价值(AI评估下一次落子位置的价值)
int evaluate_pos(int x, int y, int player)
{
    // 临时模拟落子（确保评估准确）
    int original = board[x][y];
    board[x][y] = player;

    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        int dx = direction[i][0], dy = direction[i][1];
        int opponent = (player == PLAYER) ? AI : PLAYER;

        // 获取当前玩家（自身）的棋型信息
        DirInfo self_info = count_specific_direction(x, y, dx, dy, player);
        // 获取对手的棋型信息
        DirInfo oppo_info = count_specific_direction(x, y, dx, dy, opponent);

        // 对手威胁评估（防守逻辑）
        if (oppo_info.continuous_chess >= 4)
        {
            board[x][y] = original; // 恢复棋盘
            return 10000;           // 对手四连珠必须阻止
        }
        else if (oppo_info.continuous_chess == 3)
        {
            // 玩家三连珠
            if (oppo_info.check_start && oppo_info.check_end) // 仅当两端开放才高威胁
            {
                score += 5000; // 活三（两端开放），高威胁
            }
            else if (oppo_info.check_start || oppo_info.check_end) // 死三（两端封闭）不加分
            {
                score += 2000; // 眠三（一端开放），中等威胁
            }
        }

        // 自身机会评估（进攻逻辑）
        if (self_info.continuous_chess >= 5)
        {
            board[x][y] = original; // 恢复棋盘
            return 20000;           // 五连珠直接获胜
        }
        else if (self_info.continuous_chess == 4)
        {
            score += 8000; // 四连珠必胜
        }
        else if (self_info.continuous_chess == 3)
        {
            // AI三连珠
            if (self_info.check_start && self_info.check_end) // 两端开放才高价值
            {
                score += 4000; // 活三（两端开放），高价值
            }
            else if (self_info.check_start || self_info.check_end) // 死三（两端封闭）不加分
            {
                score += 1500; // 眠三（一端开放），中等价值
            }
        }
        else if (self_info.continuous_chess == 2)
        {
            score += 1000; // 二连珠基础分
        }
    }

    board[x][y] = original; // 恢复棋盘

    return score;
}

// !AI落子算法
void ai_move()
{
    int best_score = -1, best_x = -1, best_y = -1;

    // 遍历整个棋盘
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // 跳过已落子位置
            if (board[i][j] != EMPTY)
            {
                continue;
            }

            // 综合评估位置对AI的进攻价值和防御价值
            int score = evaluate_pos(i, j, AI) + evaluate_pos(i, j, PLAYER) * 0.5;

            // 更新最佳位置
            if (score > best_score)
            {
                best_score = score;
                best_x = i;
                best_y = j;
            }
        }
    }

    // 在最佳位置落子
    if (best_x != -1 && best_y != -1)
    {
        board[best_x][best_y] = AI;
        steps[step_count++] = (Step){AI, best_x, best_y};
        printf("AI落子于(%d, %d)\n", best_x + 1, best_y + 1);
    }
}

// !复盘游戏过程
void review_process()
{
    printf("\n===== 复盘记录(总步数：%d) =====\n", step_count);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // 清空缓冲区

    // 重建临时棋盘
    int temp_board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    memset(temp_board, EMPTY, sizeof(temp_board));

    for (int i = 0; i < step_count; i++)
    {
        Step s = steps[i];
        // 获取坐标
        temp_board[s.x][s.y] = s.player;

        printf("\n===== 五子棋人机对战(%dX%d棋盘) =====", BOARD_SIZE, BOARD_SIZE);
        printf("\n    第%d步/%d步: %s 落子于(%d, %d)\n",
               i + 1, step_count,
               (s.player == PLAYER) ? "玩家" : "AI", //* 如果s.player == PLAYER, 则打印“玩家”,反之打印“AI”
               s.x + 1, s.y + 1);                    // 显示为(行,列)
        printf("===== 五子棋人机对战(%dX%d棋盘) =====\n", BOARD_SIZE, BOARD_SIZE);

        // 打印当前棋盘状态
        printf("  ");
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            printf("%2d", col + 1);
        }
        printf("\n");

        for (int row = 0; row < BOARD_SIZE; row++)
        {
            printf("%2d ", row + 1);
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (temp_board[row][col] == PLAYER)
                    printf("x ");
                else if (temp_board[row][col] == AI)
                    printf("○ ");
                else
                    printf("· ");
            }
            printf("\n");
        }

        if (i < step_count - 1)
        {
            printf("\n按Enter继续下一步...");
            while (getchar() != '\n')
                ;
        }
    }
    printf("\n复盘结束！按Enter返回...");

    getchar();
}