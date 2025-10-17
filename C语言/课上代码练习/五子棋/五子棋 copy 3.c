#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief ��ָ��Ƶ�powershell
 * gcc "���ϴ�����ϰ\������\������ copy 3.c" -o output/������ copy 3.exe
 * @brief ��ָ��Ƶ�powershell
 * .\output\������ copy 3.exe
 */

// !�궨��
#define MAX_BOARD_SIZE 25                           //* ���֧�����̳ߴ�(5x5��25x25)
int BOARD_SIZE = 15;                                //* ʵ��ʹ�õ����̳ߴ�(Ĭ��15)
#define PLAYER 1                                    //* ������ӱ�ʶ��
#define AI 2                                        //* AI���ӱ�ʶ��
#define EMPTY 0                                     //* ��λ�ñ�ʶ��
#define MAX_STEPS (MAX_BOARD_SIZE * MAX_BOARD_SIZE) //* ������������ܸ�����

// !ȫ�ֱ���
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};               //* ����״̬�洢����(Ĭ������ȫ��Ϊ0)
int AI_DEPTH = 3;                                              //* AI˼�����(Ĭ��3��)
const int direction[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}}; //* �ĸ��������¡����ҡ����¡�����

// !���Ӳ���ṹ��
typedef struct // ���ӽṹ��
{
    int player; // ���ӷ���ʶ
    int x, y;   // ����λ��
} Step;

// !������Ϣ�ṹ��
typedef struct
{
    int continuous_chess; // ������������
    bool check_start;     // ������㷽���Ƿ񿪷ţ���λ��
    bool check_end;       // �����յ㷽���Ƿ񿪷ţ���λ��
} DirInfo;

Step steps[MAX_STEPS]; // �洢�������Ӳ��������
int step_count = 0;    // ��ǰ����������

// !��ʼ�����̣��������״̬�Ͳ�����¼
void empty_board();

// !��ӡ��ǰ����״̬
void print_board();

// !���λ���Ƿ���Ч�������̷�Χ����Ϊ��λ��
bool have_space(int x, int y);

// !������Ӳ���
bool player_move(int x, int y);

// !�����ض�����������ͬɫ��������
DirInfo count_specific_direction(int x, int y, int dx, int dy, int player);

// !����ض�λ�����Ӻ��Ƿ��ʤ
bool check_win(int x, int y, int player);

// !�����ض�λ�öԵ�ǰ��ҵļ�ֵ
int evaluate_pos(int x, int y, int player);

// !����-�¼�֦�������������(��С�����㷨ʵ��)
int dfs(int x, int y, int player, int depth, int alpha, int beta, bool is_maximizing);

// !AI�����㷨
void ai_move(int depth);

// !������Ϸ����
void review_process();

// !����������Ϸ���̿���
int main()
{
    // ��ʼ���׶Σ���ȡ���̳ߴ��AI�Ѷ�
    printf("===== �������˻���ս =====\n");
    printf("ͨ�����̴�С��Ϊ��������(13X13)����׼����(15X15)����������(19X19)\n");
    printf("���������̴�С(5~%d)(Ĭ��Ϊ��׼����):", MAX_BOARD_SIZE);
    scanf("%d", &BOARD_SIZE);

    // У�������Ƿ�Ϸ������Ϸ�ʱʹ��Ĭ��ֵ
    if (BOARD_SIZE < 5 || BOARD_SIZE > MAX_BOARD_SIZE)
    {
        BOARD_SIZE = 15;
        printf("������Ч��ʹ��Ĭ�ϱ�׼����15X15\n");
    }


    printf("������AI˼�����(1-5, ��ֵԽ��AIԽǿ��˼��ʱ��Խ��, Ĭ��Ϊ3):");
    scanf("%d", &AI_DEPTH);

    // У��AI��ȷ�Χ
    if (AI_DEPTH < 1 || AI_DEPTH > 5)
    {
        AI_DEPTH = 3;
        printf("������Ч��ʹ��Ĭ�����3\n");
    }

    empty_board(); // ��ʼ������
    printf("===== �������˻���ս(%dX%d����, AI���%d) =====", BOARD_SIZE, BOARD_SIZE, AI_DEPTH);
    print_board(); // ��ӡ��ʼ������

    // ��Ϸ��ѭ��
    while (1)
    {
        // ��һغ�
        int x, y;
        printf("\n��������������(�� �У�1~%d):", BOARD_SIZE);
        scanf("%d %d", &x, &y);
        // ת���û������1-base����Ϊ0-base����
        x--;
        y--;

        // ��֤��ִ������ƶ�
        if (!player_move(x, y)) // ��Чλ�ô���
        {
            printf("������Ч�����������롣\n");
            continue; // ����ѭ����ͷ��������
        }
        print_board(); // ���º��ӡ����

        // �������Ƿ��ʤ
        if (check_win(x, y, PLAYER))
        {
            printf("\n��һ�ʤ��\n");
            review_process(); // չʾ����
            break;            // �˳���Ϸѭ��
        }

        // AI�غ�
        printf("\nAI˼����...\n");
        ai_move(AI_DEPTH); // AI�����������λ��
        print_board();     // չʾAI���Ӻ������

        // ���AI�Ƿ��ʤ��ͨ�����һ����
        Step last_step = steps[step_count - 1]; // ��ȡ���һ��
        if (check_win(last_step.x, last_step.y, AI))
        {
            printf("\nAI��ʤ��\n");
            review_process(); // չʾ����
            break;            // �˳���Ϸѭ��
        }

        // ���ƽ�֣�����������
        if (step_count == BOARD_SIZE * BOARD_SIZE)
        {
            printf("\nƽ�֣�\n");
            review_process(); // չʾ����
            break;            // �˳���Ϸѭ��
        }
    }

    return 0;
}

// !��ʼ�����̣��������״̬�Ͳ�����¼
void empty_board()
{
    // ��ʼ������״̬Ϊȫ��
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    step_count = 0; // ���ò���������
}

// !��ӡ��ǰ����״̬
void print_board()
{
    // ��ӡ�кţ�1-BOARD_SIZE��ʾ��
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d", i + 1);
        if (i + 1 == 9) // �����к�9��10+�Ķ���
            printf(" ");
    }
    printf("\n");

    // ���д�ӡ��������
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d ", i + 1); // ��ӡ�кţ�1-BOARD_SIZE��
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == PLAYER)
                printf("x "); // �������
            else if (board[i][j] == AI)
                printf("�� "); // AI����(ʹ�á���ʾ)
            else
                printf("�� "); // ��λ
        }
        printf("\n"); // ÿ�н�������
    }
}

// !���λ���Ƿ���Ч�������̷�Χ����Ϊ��λ��
bool have_space(int x, int y)
{
    // У�������Ƿ��ڷ�Χ���Ҹ�λ��Ϊ��
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY);
}

// !������Ӳ���
bool player_move(int x, int y)
{
    // λ����Ч�򷵻�false
    if (!have_space(x, y))
        return false;

    // ��������״̬
    board[x][y] = PLAYER;
    // ��¼���Ӳ��裺��ұ�ʶ������
    steps[step_count++] = (Step){PLAYER, x, y};
    return true;
}

// !�����ض�����������ͬɫ��������
DirInfo count_specific_direction(int x, int y, int dx, int dy, int player)
{
    DirInfo info;
    info.continuous_chess = 1; // ��ʼλ���Ѿ���һ������
    info.check_start = false;  // ��㷽���Ƿ񿪷�
    info.check_end = false;    // �յ㷽���Ƿ񿪷�

    // ���������dx, dy��
    int nx = x + dx, ny = y + dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++; // �������Ӽ�������
        nx += dx;                // �ص�ǰ����ǰ��
        ny += dy;
    }
    // �ж�������˵��Ƿ񿪷ţ�������λ��
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
        if (board[nx][ny] == EMPTY)
            info.check_end = true;

    // ��鷴����-dx, -dy��
    nx = x - dx, ny = y - dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++; // �������Ӽ�������
        nx -= dx;                // ���෴����ǰ��
        ny -= dy;
    }
    // �жϷ�����˵��Ƿ񿪷ţ�������λ��
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
        if (board[nx][ny] == EMPTY)
            info.check_start = true;

    return info;
}

// !����ض�λ�����Ӻ��Ƿ��ʤ
bool check_win(int x, int y, int player)
{
    // ����ĸ������Ƿ����������
    for (int i = 0; i < 4; i++)
    {
        DirInfo info = count_specific_direction(x, y, direction[i][0], direction[i][1], player);
        if (info.continuous_chess >= 5) // ��������>=5����ʤ
            return true;
    }
    return false; // �ĸ�����û��������
}

// !�����ض�λ�öԵ�ǰ��ҵļ�ֵ
int evaluate_pos(int x, int y, int player)
{
    // ����ԭʼֵ���ڻ�ԭ
    int original = board[x][y];
    // ģ���ڸ�λ������
    board[x][y] = player;

    int total_score = 0;      // �ܷ�
    int line_scores[4] = {0}; // �ĸ�����ĵ÷�

    // �����ĸ������������
    for (int i = 0; i < 4; i++)
    {
        int dx = direction[i][0], dy = direction[i][1];
        // ��ȡ��ǰ�����ϵ�������Ϣ
        DirInfo info = count_specific_direction(x, y, dx, dy, player);

        // ֱ���γ�������Ϊ��ʤ
        if (info.continuous_chess >= 5)
        {
            board[x][y] = original; // ��ԭ����
            return 1000000;         // ��������
        }

        // ������������������
        switch (info.continuous_chess)
        {
        case 4:                                     // ������
            if (info.check_start && info.check_end) // ����(���˿���)
                line_scores[i] = 100000;
            else if (info.check_start || info.check_end) // ����(һ�˿���)
                line_scores[i] = 10000;
            else // ����(���˷��)
                line_scores[i] = 500;
            break;

        case 3:                                     // ������
            if (info.check_start && info.check_end) // ����
                line_scores[i] = 5000;
            else if (info.check_start || info.check_end) // ����
                line_scores[i] = 1000;
            else // ����
                line_scores[i] = 50;
            break;

        case 2:                                     // ������
            if (info.check_start && info.check_end) // ���
                line_scores[i] = 500;
            else if (info.check_start || info.check_end) // �߶�
                line_scores[i] = 100;
            else // ����
                line_scores[i] = 10;
            break;

        case 1:                                     // ����
            if (info.check_start && info.check_end) // ����λ��
                line_scores[i] = 50;
            else if (info.check_start || info.check_end) // �뿪��λ��
                line_scores[i] = 10;
            else // ���λ��
                line_scores[i] = 1;
            break;
        }
    }

    // �����ܷ֣���߷����+��������ּ�Ȩ��
    int max_score = 0;
    int sum_score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (line_scores[i] > max_score)
            max_score = line_scores[i];
        sum_score += line_scores[i];
    }
    total_score = max_score * 10 + sum_score; // ������Ȩ�ظ���

    // λ�ý�����Խ�������ķ���Խ��
    int center_x = BOARD_SIZE / 2;
    int center_y = BOARD_SIZE / 2;
    int distance = abs(x - center_x) + abs(y - center_y); // �����پ���
    int position_bonus = 50 * (BOARD_SIZE - distance);    // ��������Խ������Խ��

    board[x][y] = original;              // ��ԭ����״̬
    return total_score + position_bonus; // ������������
}

// !����-�¼�֦�������������(��С�����㷨ʵ��)
int dfs(int x, int y, int player, int depth, int alpha, int beta, bool is_maximizing)
{
    // ��鵱ǰ�����Ƿ��ʤ
    if (check_win(x, y, player))
    {
        return (player == AI) ? 1000000 + depth : -1000000 - depth;
    }

    // �ﵽ������Ȼ�ƽ��
    if (depth == 0 || step_count >= BOARD_SIZE * BOARD_SIZE)
    {
        return evaluate_pos(x, y, AI) - evaluate_pos(x, y, PLAYER);
    }

    int best_score = is_maximizing ? -1000000 : 1000000;

    // �������п�������λ��
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != EMPTY)
                continue;

            // ģ�⵱ǰ�������
            board[i][j] = player;
            step_count++;

            // �ݹ�����(�л���Һ��������)
            int current_score = dfs(i, j, (player == AI) ? PLAYER : AI, depth - 1, alpha, beta, !is_maximizing);

            // ��������
            board[i][j] = EMPTY;
            step_count--;

            // ����ֵ���(AI)�߼�
            if (is_maximizing)
            {
                best_score = (current_score > best_score) ? current_score : best_score;
                alpha = (best_score > alpha) ? best_score : alpha;
                // ����֦
                if (beta <= alpha)
                {
                    break;
                }
            }
            // ��Сֵ���(����)�߼�
            else
            {
                best_score = (current_score < best_score) ? current_score : best_score;
                beta = (best_score < beta) ? best_score : beta;
                // �¼�֦
                if (beta <= alpha)
                {
                    break;
                }
            }
        }
        if ((is_maximizing && best_score >= beta) || (!is_maximizing && best_score <= alpha))
        {
            break; // ��ǰ�˳����ѭ��
        }
    }

    return best_score;
}

// !ʹ�ô���-�¼�֦��DFS��С�����㷨����AI����
void ai_move(int depth)
{
    // 1. ���ȼ���Ƿ���Ҫ��ֹ��ҵ�������������ӻ���
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != EMPTY)
                continue;

            // ģ������ڴ�λ������
            board[i][j] = PLAYER;
            bool need_block = false;

            // ����ĸ�����
            for (int k = 0; k < 4; k++)
            {
                DirInfo info = count_specific_direction(i, j, direction[k][0], direction[k][1], PLAYER);

                // ���������γ���������������һ�˿���
                if (info.continuous_chess >= 4 && (info.check_start || info.check_end))
                {
                    need_block = true;
                    break;
                }

                // ���������γ����ӻ��������˿���
                if (info.continuous_chess == 3 && info.check_start && info.check_end)
                {
                    need_block = true;
                    break;
                }
            }

            board[i][j] = EMPTY; // �ָ�����

            if (need_block)
            {
                // �����ڴ�λ��������ֹ
                board[i][j] = AI;
                steps[step_count++] = (Step){AI, i, j};
                printf("AI����(%d, %d)\n", i + 1, j + 1);
                return;
            }
        }
    }

    // 2. ���û����Ҫ������ֹ�����������������
    int best_score = -1000000;
    int best_x = -1, best_y = -1;

    // �����������п�λ
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != EMPTY)
                continue;

            // ֻ�����������Ӹ���(2��Χ��)
            bool has_nearby_stone = false;
            for (int di = -2; di <= 2; di++)
            {
                for (int dj = -2; dj <= 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < BOARD_SIZE &&
                        nj >= 0 && nj < BOARD_SIZE)
                    {
                        if (board[ni][nj] != EMPTY)
                        {
                            has_nearby_stone = true;
                            break;
                        }
                    }
                }
                if (has_nearby_stone)
                    break;
            }
            if (!has_nearby_stone && step_count > 10)
                continue;

            // ģ��AI����
            board[i][j] = AI;
            int current_score = dfs(i, j, PLAYER, depth, -1000000, 1000000, false);
            board[i][j] = EMPTY;

            // �������λ��
            if (current_score > best_score)
            {
                best_score = current_score;
                best_x = i;
                best_y = j;
            }
        }
    }

    // ִ���������
    if (best_x != -1 && best_y != -1)
    {
        board[best_x][best_y] = AI;
        steps[step_count++] = (Step){AI, best_x, best_y};
        printf("AI����(%d, %d)\n", best_x + 1, best_y + 1);
    }
}

// !������Ϸ����
void review_process()
{
    printf("\n===== ���̼�¼(�ܲ�����%d) =====\n", step_count);
    // ������뻺����
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // ������ʱ��������
    int temp_board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    memset(temp_board, EMPTY, sizeof(temp_board)); // ��ʼ��Ϊ������

    // ��������Ϸ����
    for (int i = 0; i < step_count; i++)
    {
        Step s = steps[i];               // ��ȡ��ǰ����
        temp_board[s.x][s.y] = s.player; // ����ʱ����������

        // ��ӡ��ǰ������Ϣ
        printf("\n===== �������˻���ս(%dX%d����) =====", BOARD_SIZE, BOARD_SIZE);
        printf("\n    ��%d��/%d��: %s ������(%d, %d)\n",
               i + 1, step_count,
               (s.player == PLAYER) ? "���" : "AI", // ��Ŀ�����ѡ����ʾ�ı�
               s.x + 1, s.y + 1);                    // ��ʾ1-base����

        // ��ӡ��ǰ��������
        printf("  ");
        for (int col = 0; col < BOARD_SIZE; col++)
            printf("%2d", col + 1); // �к�
        printf("\n");

        for (int row = 0; row < BOARD_SIZE; row++)
        {
            printf("%2d ", row + 1); // �к�
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (temp_board[row][col] == PLAYER)
                    printf("x ");
                else if (temp_board[row][col] == AI)
                    printf("�� ");
                else
                    printf("�� ");
            }
            printf("\n"); // �н�������
        }

        // ����������һ�����ȴ��û���������
        if (i < step_count - 1)
        {
            printf("\n��Enter������һ��...");
            while (getchar() != '\n')
                ; // �ȴ��س�
        }
    }
    printf("\n���̽�������Enter����...");
    
    getchar(); // �ȴ��û�����
}