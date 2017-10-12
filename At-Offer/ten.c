#include<stdio.h>

int GetNumsOne(int m)
{
    int base = 1;
    int weight;
    int round = m;
    int count = 0;
    
    while (round > 0)
    {
        weight = round % 10;
        round = round/10;
        if (weight > 1)
        {
            count += round * base + base;
        }
        else if (weight == 1)
        {
            count += round * base + (m % base + 1);
        }
        else
        {
            count += round * base;
        }

        base *= 10;
    }

    return count;
}

void main()
{
    int m;
    int num;
    while (scanf("%d", &m) != EOF)
    {
        num = GetNumsOne(m);
        printf("%d\n", num);
    }
}
