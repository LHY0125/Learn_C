// 计算含运算符 '&'（取两数较小值）与 '|'（取两数较大值）的表达式
// 两者同优先级，按从左到右结合；遇到括号优先计算括号内表达式。
// 输入：一行字符串，仅由数字、&、|、(、) 组成
// 输出：一个整数，表示表达式的值

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static inline int min_i(int a, int b) { return a < b ? a : b; }
static inline int max_i(int a, int b) { return a > b ? a : b; }

static inline void apply_top(int *vals, int *vtop, char *ops, int *otop) {
    char op = ops[--(*otop)];
    int b = vals[--(*vtop)];
    int a = vals[--(*vtop)];
    int r = (op == '&') ? min_i(a, b) : max_i(a, b);
    vals[(*vtop)++] = r;
}

int main(void) {
    // 读取整行输入
    char *line = NULL;
    size_t cap = 0;
    {
        // getline 若不可用则用 fgets 简易读取
        // Windows 平台无 getline，这里使用 fgets
        size_t bufcap = 16384; // 大于题目约束的 10000
        line = (char*)malloc(bufcap);
        if (!line) return 1;
        if (!fgets(line, (int)bufcap, stdin)) return 0;
        size_t len = strlen(line);
        // 去掉行尾 CR/LF
        while (len && (line[len-1] == '\n' || line[len-1] == '\r')) line[--len] = '\0';
        cap = len + 1;
    }

    size_t L = strlen(line);
    int *vals = (int*)malloc((L + 1) * sizeof(int));
    char *ops = (char*)malloc(L + 1);
    if (!vals || !ops) return 1;
    int vtop = 0, otop = 0;

    for (size_t i = 0; i < L;) {
        char c = line[i];
        if (isspace((unsigned char)c)) { ++i; continue; } // 忽略空白
        if (c >= '0' && c <= '9') {
            int x = 0;
            while (i < L && line[i] >= '0' && line[i] <= '9') {
                x = x * 10 + (line[i] - '0');
                ++i;
            }
            vals[vtop++] = x;
        } else if (c == '&' || c == '|') {
            // 同优先级：在遇到 '(' 之前，应用所有已入栈的运算符
            while (otop > 0 && ops[otop - 1] != '(') {
                apply_top(vals, &vtop, ops, &otop);
            }
            ops[otop++] = c;
            ++i;
        } else if (c == '(') {
            ops[otop++] = c;
            ++i;
        } else if (c == ')') {
            while (otop > 0 && ops[otop - 1] != '(') {
                apply_top(vals, &vtop, ops, &otop);
            }
            if (otop > 0 && ops[otop - 1] == '(') --otop; // 弹出左括号
            ++i;
        } else {
            // 非法字符：跳过以增强鲁棒性
            ++i;
        }
    }

    while (otop > 0) {
        apply_top(vals, &vtop, ops, &otop);
    }

    if (vtop > 0) printf("%d\n", vals[vtop - 1]);

    free(vals);
    free(ops);
    free(line);
    return 0;
}