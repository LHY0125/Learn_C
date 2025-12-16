#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        char str[10001];
        scanf("%s", str);
        
        // 统计每个小写字母的出现次数
        int count[26] = {0}; // a-z对应0-25
        
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            char c = str[i];
            // 只统计小写字母
            if (c >= 'a' && c <= 'z')
            {
                count[c - 'a']++;
            }
        }
        
        // 找出出现次数最多的字母，如果次数相同则选择字典序最小的
        int max_count = 0;
        char result = 'a';
        
        // 从a到z遍历，保证字典序最小
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > max_count)
            {
                max_count = count[i];
                result = 'a' + i;
            }
        }
        
        printf("%c\n", result);
    }
    
    return 0;
}