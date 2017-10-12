#include<stdio.h>

int FindOneNumAppearOne(int *a, int n)
{
    int dt = 0;
    int i;
    for (i=0; i<n; i++)
    {
        dt ^= *(a+i);
    }

    return dt;

}

void main()
{
    int A[] = {1, 3, 4, 3, 4, 1, 9, 10, 11, 9, 10};
    int len = sizeof(A)/sizeof(int);
    int num = FindOneNumAppearOne(A, len);
    printf("%d\n", num);
}
