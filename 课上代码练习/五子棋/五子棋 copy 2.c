#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// !�궨��
#define MAX_BOARD_SIZE 25                           //* ���֧�����̳ߴ�
int BOARD_SIZE = 15;                                //* ʵ��ʹ�õ����̳ߴ�(Ĭ��15)
#define PLAYER 1                                    //* ������ӱ�ʶ��
#define AI 2                                        //* AI���ӱ�ʶ��
#define EMPTY 0                                     //* ��λ�ñ�ʶ��
#define MAX_STEPS (MAX_BOARD_SIZE * MAX_BOARD_SIZE) //* ������������ܸ�����

// !ȫ�ֱ���
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};               //* ����״̬�洢����(Ĭ������ȫ��Ϊ0)
const int direction[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}}; //* �ĸ��������¡����ҡ����¡�����

// !���Ӳ���ṹ��
typedef struct          // ���ӽṹ��
{
    int player;         // ���ӷ���ʶ
    int x, y;           // ����λ��
} Step;

Step steps[MAX_STEPS];      // �洢�������Ӳ���

// !������Ϣ�ṹ��
typedef struct
{
    int continuous_chess;   // ������������
    bool check_start;       // ������㷽���Ƿ񿪷ţ���λ��
    bool check_end;         // �����յ㷽���Ƿ񿪷ţ���λ��
} DirInfo;

int step_count = 0;         // ��ǰ����������

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

// !AI�����㷨
void ai_move();

// !������Ϸ����
void review_process();

// !����������Ϸ���̿���
int main()
{
    // ��ʼ���׶Σ���ȡ���̳ߴ�
    printf("===== �������˻���ս =====\n");
    printf("ͨ�����̴�С��Ϊ��������(13X13)����׼����(15X15)����������(19X19)\n");
    printf("���������̴�С(5~%d)(Ĭ��Ϊ��׼����):", MAX_BOARD_SIZE);
    scanf("%d", &BOARD_SIZE);
    if (BOARD_SIZE < 5 || BOARD_SIZE > MAX_BOARD_SIZE)
    {
        BOARD_SIZE = 15;
        printf("������Ч��ʹ��Ĭ�ϱ�׼����15X15\n");
    }

    empty_board();
    printf("===== �������˻���ս(%dX%d����) =====", BOARD_SIZE, BOARD_SIZE);
    print_board();

    // ��Ϸ��ѭ��
    while (1)
    {
        // ��һغ�
        int x, y;
        printf("\n��������������(�� �У�1~%d):", BOARD_SIZE);
        scanf("%d %d", &x, &y);
        // ת��Ϊ0-BOARD_SIZE����(תΪ���̵�����)
        x--;
        y--;

        // ��֤��ִ������ƶ�
        if (!player_move(x, y))
        {
            printf("������Ч�����������롣\n");
            continue;
        }
        print_board();

        // �������Ƿ��ʤ
        if (check_win(x, y, PLAYER))
        {
            printf("\n��һ�ʤ��\n");
            review_process();
            break;
        }

        // AI�غ�
        printf("\nAI˼����...\n");
        ai_move();
        print_board();

        // ���AI�Ƿ��ʤ
        Step last_step = steps[step_count - 1];
        if (check_win(last_step.x, last_step.y, AI))
        {
            printf("\nAI��ʤ��\n");
            review_process();
            break;
        }

        // ���ƽ�֣�����������
        if (step_count == BOARD_SIZE * BOARD_SIZE)
        {
            printf("\nƽ�֣�\n");
            review_process();
            break;
        }
    }

    return 0;
}

// !��ʼ�����̣��������״̬�Ͳ�����¼
void empty_board()
{
    // ��ʼ������״̬
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    step_count = 0;
}

// !��ӡ��ǰ����״̬
void print_board()
{
    // ��ӡ�кţ�1-BOARD_SIZE��ʾ��
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d", i + 1);
        if (i + 1 == 9)        // ������λ���кŵĶ���
            printf(" ");
    }
    printf("\n");

    // ��ӡÿ����������
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d ", i + 1); // ��ӡ�кţ�1-BOARD_SIZE��
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == PLAYER)
                printf("x ");  // �������
            else if (board[i][j] == AI)
                printf("�� ");  // AI����
            else
                printf("�� ");  // ��λ
        }
        printf("\n");
    }
}

// !���λ���Ƿ���Ч�������̷�Χ����Ϊ��λ��
bool have_space(int x, int y)
{
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY);
}

// !������Ӳ���
bool player_move(int x, int y)
{
    if (!have_space(x, y))
    {
        return false; // λ����Ч����ʧ��
    }

    board[x][y] = PLAYER;                       // ��������״̬
    steps[step_count++] = (Step){PLAYER, x, y}; // ��¼����
    return true;
}

// !�����ض�����������ͬɫ��������
DirInfo count_specific_direction(int x, int y, int dx, int dy, int player)
{
    DirInfo info;
    info.continuous_chess = 1; // ������ǰλ��
    info.check_start = false;
    info.check_end = false;

    // ���������dx, dy��
    int nx = x + dx, ny = y + dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++;
        nx += dx;
        ny += dy;
    }
    // �ж�������˵��Ƿ񿪷�
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
    {
        if (board[nx][ny] == EMPTY)
        {
            info.check_end = true;
        }
    }

    // ��鷴����-dx, -dy��
    nx = x - dx, ny = y - dy;
    while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
    {
        info.continuous_chess++;
        nx -= dx;
        ny -= dy;
    }
    // �жϷ�����˵��Ƿ񿪷�
    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
    {
        if (board[nx][ny] == EMPTY)
        {
            info.check_start = true;
        }
    }

    return info;
}

// !����ض�λ�����Ӻ��Ƿ��ʤ
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

// !�����ض�λ�öԵ�ǰ��ҵļ�ֵ(AI������һ������λ�õļ�ֵ)
int evaluate_pos(int x, int y, int player)
{
    // ��ʱģ�����ӣ�ȷ������׼ȷ��
    int original = board[x][y];
    board[x][y] = player;

    int total_score = 0;      // �ܷ�
    int line_scores[4] = {0}; // ��¼�ĸ�����ķ���

    // �����ĸ�����
    for (int i = 0; i < 4; i++)
    {
        int dx = direction[i][0], dy = direction[i][1];

        // ��ȡ��ǰ��ҵ�������Ϣ
        DirInfo info = count_specific_direction(x, y, dx, dy, player);

        // ����Ƿ�ֱ���γ�������
        if (info.continuous_chess >= 5)
        {
            board[x][y] = original; // �ָ�����
            return 1000000;         // ������ֱ�ӷ�����߷�
        }

        // ������ͬ���͵ļ�ֵ
        switch (info.continuous_chess)
        {
        // ������
        case 4:
            // ���ģ����˿��ţ�
            if (info.check_start && info.check_end)
            {
                line_scores[i] = 100000; // ��ʤ����
            }
            // ���ģ�һ�˿��ţ�
            else if (info.check_start || info.check_end)
            {
                line_scores[i] = 10000; // ��
          }
            // ���ģ����˷�գ�
            else
            {
                line_scores[i] = 500; // �ͼ�ֵ
            }
            break;

        // ������
        case 3:
            // ���������˿��ţ�
            if (info.check_start && info.check_end)
            {
                line_scores[i] = 5000; // �߼�ֵ
            }
            // ������һ�˿��ţ�
            else if (info.check_start || info.check_end)
            {
                line_scores[i] = 1000; // �еȼ�ֵ
            }
            // ���������˷�գ�
            else
            {
                line_scores[i] = 50; // �ͼ�ֵ
            }
            break;

        // ������
        case 2:
            // ��������˿��ţ�
            if (info.check_start && info.check_end)
            {
                line_scores[i] = 500; // ��չǱ����
            }
            // �߶���һ�˿��ţ�
            else if (info.check_start || info.check_end)
            {
                line_scores[i] = 100; // ����Ǳ��
            }
            // ���������˷�գ�
            else
            {
                line_scores[i] = 10; // �����޼�ֵ
            }
            break;

        // ����
        case 1:
            // ���ӵ����˿���
            if (info.check_start && info.check_end)
            {
                line_scores[i] = 50; // δ��Ǳ��
            }
            // ���ӵ�һ�˿���
            else if (info.check_start || info.check_end)
            {
                line_scores[i] = 10; // ����Ǳ��
            }
            // ������
            else
            {
                line_scores[i] = 1; // �����޼�ֵ
            }
            break;

        // �������ϣ��Ѵ���
        default:
            break;
        }
    }

    // �����ܷ֣�ȡ��߷����+��������ּ�Ȩ
    int max_score = 0;
    int sum_score = 0;

    for (int i = 0; i < 4; i++)
    {
        if (line_scores[i] > max_score)
        {
            max_score = line_scores[i];
        }
        sum_score += line_scores[i];
    }

    // ������Ȩ�ظߣ���������Ȩ�ص�
    total_score = max_score * 10 + sum_score;

    board[x][y] = original; // �ָ�����

    // ���λ��Ȩ�أ�����λ��>��Եλ��
    int center_x = BOARD_SIZE / 2;
    int center_y = BOARD_SIZE / 2;
    int distance = abs(x - center_x) + abs(y - center_y);
    int position_bonus = 50 * (BOARD_SIZE - distance);

    return total_score + position_bonus;
}

// !AI�����㷨
void ai_move()
{
    int best_score = -1, best_x = -1, best_y = -1;

    // ������������
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // ����������λ��
            if (board[i][j] != EMPTY)
            {
                continue;
            }

            // �ۺ�����λ�ö�AI�Ľ�����ֵ�ͷ�����ֵ
            int score = evaluate_pos(i, j, AI) + evaluate_pos(i, j, PLAYER) * 0.5;

            // �������λ��
            if (score > best_score)
            {
                best_score = score;
                best_x = i;
                best_y = j;
            }
        }
    }

    // �����λ������
    if (best_x != -1 && best_y != -1)
    {
        board[best_x][best_y] = AI;
        steps[step_count++] = (Step){AI, best_x, best_y};
        printf("AI������(%d, %d)\n", best_x + 1, best_y + 1);
    }
}

// !������Ϸ����
void review_process()
{
    printf("\n===== ���̼�¼(�ܲ�����%d) =====\n", step_count);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;// ��ջ�����

    // �ؽ���ʱ����
    int temp_board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    memset(temp_board, EMPTY, sizeof(temp_board));

    for (int i = 0; i < step_count; i++)
    {
        Step s = steps[i];
        // ��ȡ����
        temp_board[s.x][s.y] = s.player;

        printf("\n===== �������˻���ս(%dX%d����) =====", BOARD_SIZE, BOARD_SIZE);
        printf("\n    ��%d��/%d��: %s ������(%d, %d)\n",
               i + 1, step_count,
               (s.player == PLAYER) ? "���" : "AI",    //* ���s.player == PLAYER, ���ӡ����ҡ�,��֮��ӡ��AI��
               s.x + 1, s.y + 1); // ��ʾΪ(��,��)
        printf("===== �������˻���ս(%dX%d����) =====\n", BOARD_SIZE, BOARD_SIZE);

        // ��ӡ��ǰ����״̬
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
                    printf("�� ");
                else
                    printf("�� ");
            }
            printf("\n");
        }

        if (i < step_count - 1)
        {
            printf("\n��Enter������һ��...");
            while (getchar() != '\n')
                ;
        }
    }
    printf("\n���̽�������Enter����...");

    getchar();
}