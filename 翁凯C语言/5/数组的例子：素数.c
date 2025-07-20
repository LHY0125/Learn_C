#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#define num 100

// !判断能被已知的且为素数的数整除

int sushu(int x, int primes[], int count);

int main()
{
    //const int num=100;
    int prime[num] = {2};
    int count = 1;
    int i=3;
    
    while (count<num)
    {
        if (sushu(i,prime,count))
        {
            prime[count] = i;
            count++;
        }
        i++;
    }

    for (i = 0; i < num;i++)
    {
        printf("%d", prime[i]);
        if ((i+1)%5==0)
        {
            printf("\n");
        }
        else
        {
            printf("\t");
        }
    }

    return 0;
}

// 判断能被已知的且为素数的数整除
int sushu(int x, int known_sushu[], int num_sushu) 
// x为要判断的数，known_sushu为已知的素数，num_sushu为已知的素数的个数
{
    int ret = 1;
    int i;

    for (i = 0; i < num_sushu;i++)
    {
        if (x % known_sushu[i]==0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}