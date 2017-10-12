#include<stdio.h>
#include<stdlib.h>


int MergePairsBetweenArray(int *arr, int *brr, int start, int mid, int end)
{
    int i = mid;
    int j = end;
    int k = end;
    int count = 0;

    while (i >= start && j >=mid + 1)
    {
        if (arr[i] > arr[j])
        {
            brr[k--] = arr[i--];
            count += j - mid;
        }
        else{
        
            brr[k--] = arr[j--];
        }
    }

    while (i >= start)
    {
        brr[k--] = arr[i--];
    }

    while (j >= mid + 1)
    {
        brr[k--] = arr[j--];
    }

    int m;

    for (m = end; m > k; m--)
    {
        arr[m] = brr[m];
    }
    return count;
}

int CountMergePairs(int *arr, int *brr, int start, int end)
{
    int numbers = 0;
    
    if (start < end)
    {
        int mid = (start + end) >> 1;
        numbers += CountMergePairs(arr, brr, start, mid);
        numbers += CountMergePairs(arr, brr, mid + 1, end);
        numbers += MergePairsBetweenArray(arr, brr, start, mid, end);
    }
    
    return numbers;
}

int CountTotalPairs(int *arr, int len)
{
    if (arr == NULL || len < 2 )
        return 0;

    int *brr = (int *)malloc(sizeof(int) * len);
    int sum = CountMergePairs(arr,brr,0,len-1);
    free(brr);
    return sum;
}

void main()
{
    int n;
    int *arr;

    while (scanf("%d", &n) != EOF)
    {
        arr = (int *)malloc(sizeof(int) * n);
        int i;

        for (i=0; i<n; i++)
        {
            scanf("%d", arr+i);
        }

        printf("The pairs:%d\n", CountTotalPairs(arr, n));
        free(arr);
    }

   
}
