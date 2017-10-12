#include<stdio.h>

int UglyNums[1500];


int Min(int a, int b, int c)
{
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}

int GetUglyNum(int index)
{
    if (index <= 0)
    {
        return 0;
    }
    
    UglyNums[0] = 1;
    int CurrentIndex = 1;
    
    int *p1 = UglyNums;
    int *p2 = UglyNums;
    int *p3 = UglyNums;

    while (CurrentIndex < index)
    {
        UglyNums[CurrentIndex] = Min((*p1) * 2, (*p2) * 3, (*p3) * 5);
        while ((*p1) * 2 <= UglyNums[CurrentIndex])
        {
            ++p1;
        }

        while ((*p2) * 3 <= UglyNums[CurrentIndex])
        {
            ++p2;
        }

        while ((*p3) * 5 <= UglyNums[CurrentIndex])
        {
            ++p3;
        }

        ++CurrentIndex;
    }

    int res = UglyNums[index - 1];

    return res;
}

void main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("the number is:%d\n", GetUglyNum(n));
    }
}
