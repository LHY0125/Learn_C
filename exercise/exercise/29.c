#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算最长合法括号子串长度及数量（数量指达到该最长长度的子串个数）
// 使用经典 DP：dp[i] 表示以 i 结尾的最长合法括号长度。
// 当 maxLen 为 0 时，按题意输出 "0 1"。

int main(void)
{
    const int MAXN = 1000005; // 题面最大长度约 1e6
    char *s = (char *)malloc(MAXN);
    if (!s) return 0;
    if (scanf("%1000000s", s) != 1) {
        free(s);
        return 0;
    }

    int n = (int)strlen(s);
    if (n == 0) {
        printf("0 1\n");
        free(s);
        return 0;
    }

    int *dp = (int *)calloc(n, sizeof(int));
    if (!dp) {
        free(s);
        return 0;
    }

    int maxLen = 0;
    int count = 1; // 若最终 maxLen 为 0，答案应为 0 1

    for (int i = 1; i < n; ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
            } else {
                int prev = i - dp[i - 1] - 1;
                if (prev >= 0 && s[prev] == '(') {
                    dp[i] = dp[i - 1] + 2 + (prev >= 1 ? dp[prev - 1] : 0);
                }
            }

            if (dp[i] > 0) {
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    count = 1;
                } else if (dp[i] == maxLen) {
                    count++;
                }
            }
        }
    }

    if (maxLen == 0) {
        printf("0 1\n");
    } else {
        printf("%d %d\n", maxLen, count);
    }

    free(dp);
    free(s);
    return 0;
}