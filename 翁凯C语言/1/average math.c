#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int number;
	int sum = 0;
	int count = 0;
	
	printf("请输入数字\n");
	scanf("%d", &number);
	while(number!=-1)
	{
		sum = sum+number;
		count = count+1;
		printf("请输入数字\n");
		scanf("%d", &number);	
	}
	
	if (count > 0)
    {
        printf("平均数是%.2f\n", (float)sum / count);
    }
    else
    {
        printf("未输入有效数字\n");
    }
		
	return 0;
}