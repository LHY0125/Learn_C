// 逆波兰式逐步规约打印
// 输入：仅含 0-9、+ - * / 和小括号 () 的中缀表达式，数字均为一位
// 要求：
// - 先将中缀转为后缀（RPN）
// - 按从左到右每次规约一个“两个数字 + 一个运算符”的三元组，得到新的后缀表达式
// - 逐行输出：首行是完整后缀表达式；之后每行比上一行少 1 个运算符和 1 个数字；最后一行只有一个数字（最终结果）
// - 令 / 为整除（向零截断），允许中间结果为负数
// - 输出格式：各符号之间以单个空格分隔；只有首行和最后一行行末保留一个空格，其他行末无空格

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int is_num;  // 1 表示数字，0 表示运算符
    int val;     // 数字值
    char op;     // 运算符字符
} Token;

// 运算符优先级：* / 高于 + -，全部左结合
static inline int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// 打印一行后缀表达式：tokens[0..n-1]
// 参数 trailing_space 控制是否在行末额外打印一个空格
static void print_tokens(const Token *t, int n, int trailing_space) {
    for (int i = 0; i < n; ++i) {
        if (t[i].is_num) {
            printf("%d", t[i].val);
        } else {
            printf("%c", t[i].op);
        }
        if (i + 1 < n) putchar(' ');
    }
    if (trailing_space) putchar(' ');
    putchar('\n');
}

// 计算 a (op) b，/ 为整除（向零），其余为常规整数算术
static inline int apply_int(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b == 0 ? 0 : a / b); // 题面保证不会越界；防御除零
        default: return 0;
    }
}

int main(void) {
    // 读取整行
    char line[256];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    size_t len = strlen(line);
    while (len && (line[len-1] == '\n' || line[len-1] == '\r')) line[--len] = '\0';

    // 中缀转后缀（shunting-yard）
    Token out[256];
    int on = 0;
    char ops[256];
    int ot = 0;

    for (size_t i = 0; i < len; ++i) {
        char c = line[i];
        if (isspace((unsigned char)c)) continue;
        if (c >= '0' && c <= '9') {
            out[on].is_num = 1;
            out[on].val = c - '0';
            out[on].op = 0;
            ++on;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int p = prec(c);
            while (ot > 0 && ops[ot - 1] != '(' && prec(ops[ot - 1]) >= p) {
                out[on].is_num = 0;
                out[on].op = ops[--ot];
                ++on;
            }
            ops[ot++] = c;
        } else if (c == '(') {
            ops[ot++] = c;
        } else if (c == ')') {
            while (ot > 0 && ops[ot - 1] != '(') {
                out[on].is_num = 0;
                out[on].op = ops[--ot];
                ++on;
            }
            if (ot > 0 && ops[ot - 1] == '(') --ot; // 弹出左括号
        } else {
            // 题面保证无需判错
        }
    }
    while (ot > 0) {
        out[on].is_num = 0;
        out[on].op = ops[--ot];
        ++on;
    }

    // 打印首行（保留行末空格）
    print_tokens(out, on, 1);

    // 逐步规约：每次找到第一个运算符（其前必有两个数字），规约为一个数字
    Token cur[256];
    memcpy(cur, out, on * sizeof(Token));
    int n = on;

    while (n > 1) {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (!cur[i].is_num) { idx = i; break; }
        }
        // 规约 cur[idx-2], cur[idx-1], cur[idx]
        int a = cur[idx - 2].val;
        int b = cur[idx - 1].val;
        int r = apply_int(a, b, cur[idx].op);
        // 将结果写回到 idx-2，并左移覆盖 idx-1 与 idx
        cur[idx - 2].is_num = 1;
        cur[idx - 2].val = r;
        // 左移 n-(idx+1) 个元素
        for (int j = idx - 1; j + 2 < n; ++j) {
            cur[j] = cur[j + 2];
        }
        n -= 2;

        // 是否最后一行：n==1 时保留行末空格，否则不保留
        print_tokens(cur, n, (n == 1));
    }

    return 0;
}