#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !����ԭ������
int num_sum(int begin, int end);

int main()
{
    printf("%d\n", num_sum(1, 10));
    printf("%d\n", num_sum(20, 30));
    printf("%d\n", num_sum(35, 45));

    return 0;
}

// !��������
int num_sum(int begin, int end)
{
    int sum = 0;
    for (int i = begin; i <= end; i++)     
    {
        sum += i;
    }
    return sum;
}