#include<stdio.h>


void swap(int A[], int m, int n)
{
    int temp;
    temp = A[m];
    A[m] = A[n];
    A[n] = temp;
}

int Partition(int A[], int left, int right)
{
    int pos = A[right];
    int index = left - 1;
    int i;

    for (i=left; i<right; i++)
    {
        if (A[i] <= pos)
        {
            swap(A, ++index, i);
        }
    }
    swap(A, index + 1, right);

    return index + 1;
}

void QuickSort(int A[], int left, int right)
{
    int prio;
    if (left < right)
    {
        prio = Partition(A, left, right);
        QuickSort(A, left, prio - 1);
        QuickSort(A, prio + 1, right);
    }

}

int FindNumber_one(int A[], int n)
{
    QuickSort(A, 0, n - 1);
    return A[n/2];
}

int FindNumber_two(int A[], int n)
{
    int result = A[0];
    int times = 0;
    int i;

    for (i=1; i<=n; i++)
    {
        if (times == 0)
        {
            result = A[i];
            times = 1;
        }
        else
        {
            if (result == A[i])
            {
                times++;
            }
            else
            {
                times--;
            }
        }
    }

    return result;
    
}

void main()
{
    int unfinds[] = {12, 33, 45, 3, 12, 3, 12, 12, 12, 7, 12};
    int size = sizeof(unfinds)/sizeof(int);
    //int number = FindNumber_one(unfinds, size);
    int number = FindNumber_two(unfinds, size);
    printf("%d\n", number);
}
