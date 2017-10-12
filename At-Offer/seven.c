#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 55


void swap (int A[], int m, int n)
{
    int temp;
    temp = A[m];
    A[m] = A[n];
    A[n] = temp;

}
int Partition(int A[], int left, int right)
{
    int prio = A[right];
    int tail = left - 1;
    int i;

    for (i=left; i<right; i++)
    {
        if (A[i] < prio)
        {
            swap(A, i, ++tail);
        }
    }
    swap (A, right, tail+1);

    return tail + 1;

}

QuickSort(int A[], int left, int right)
{
    int prio;
    if (left < right)
    {
        prio = Partition(A, left, right);
        QuickSort(A, left, prio - 1);
        QuickSort(A, prio + 1, right);
    }
}

bool IsContinuous(int *p, int n)
{
    QuickSort(p, 0, n-1);
    int sizeofzero=0;
    int sizeofgap=0;
    int i;

    for (i=0; i<n-1; i++)
    {
        if (*(p+i) == 0)
        {
            sizeofzero++;
            continue;
        }

        if (*(p+i) == *(p+i+1))
        {
            return false;
        }
        else
        {
            sizeofgap += *(p+i+1) - *(p+i) - 1;
        }
    }
    
    if (sizeofzero == sizeofgap)
    {
        return true;        
    }
    else
    {
        return false;
    }
}


void main()
{
    int n, i;
    int m[MAXSIZE];

    while (scanf("%d", &n) != EOF)
    {
        if (n<=0)
        {
            printf("input error\n");
        }

        for (i=0; i<n; i++)
        {
            scanf("%d", m+i);
        }

        bool can = IsContinuous(m, n);
        if (can)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

}


