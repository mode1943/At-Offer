#include<stdio.h>
#include<stdbool.h>


int GetPos(int t)
{
    return t & (-t);
}

bool IsEqualOne(int data, int pos)
{
    return ((data & pos) == 0) ? false : true;
}

void FindTwoNumberApearOne(int *A, int len, int *m, int *n)
{
    int dt = 0;
    int i;

    for (i=0; i<len; i++)
    {
        dt ^= *(A + i);
    }

    int pos = GetPos(dt);
    
    *m = *n = 0;
    for (i=0; i<len; i++)
    {
        if (IsEqualOne(*(A + i), pos))
        {
            *m ^= *(A + i);
        }
        else
        {
            *n ^= *(A + i);
        }
    }
}



void main()
{
    int *m, *n;
    int a, b;
    m = &a;
    n = &b;
    int A[] = {12, 34, 12, 55, 2, 34, 55, 6, 7, 7, 6, 8};
    int len = sizeof(A)/sizeof(int);
    FindTwoNumberApearOne(A, len, m, n);
    printf("%d %d\n", *m, *n);
}
