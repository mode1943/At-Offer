#include<stdio.h>
#include<stdlib.h>

int Sum(int n)
{
    int sum = n;
    int tag = (n>0) && (sum+=Sum(n-1));
    return sum;
}


void main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", Sum(n));
    }
}
