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
        
        int count = 0;
        int len = strlen(str);
        
        // 遍历字符串，统计小写字母个数
        for (int i = 0; i < len; i++)
        {
            char c = str[i];
            // 判断是否为小写字母
            if (c >= 'a' && c <= 'z')
            {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}