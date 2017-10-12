#include<stdio.h>
#include<stdlib.h>

int Add(int m, int n)
{
    int sum, add;
    
    while (n != 0)
    {
        sum = m^n;
        add = (m&n)<<1;
        m = sum;
        n = add;
    }
    return m;
}


void main()
{
    int m, n;

    while(scanf("%d %d", &m, &n) != EOF)
    {
        printf("%d\n", Add(m, n));
    }
}
