#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    while (N--)
    {
        int AH, AM, AS, BH, BM, BS;
        scanf("%d %d %d %d %d %d", &AH, &AM, &AS, &BH, &BM, &BS);
        
        // 直接相加
        int total_hours = AH + BH;
        int total_minutes = AM + BM;
        int total_seconds = AS + BS;
        
        // 处理秒的进位
        if (total_seconds >= 60)
        {
            total_minutes += total_seconds / 60;
            total_seconds = total_seconds % 60;
        }
        
        // 处理分钟的进位
        if (total_minutes >= 60)
        {
            total_hours += total_minutes / 60;
            total_minutes = total_minutes % 60;
        }
        
        printf("%d %d %d\n", total_hours, total_minutes, total_seconds);
    }
    
    return 0;
}