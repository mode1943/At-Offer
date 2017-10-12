#include<stdio.h>

int GetFirstNumber(int *a, int start, int end, int key)
{
    int mid = (start + end)>>1;

    if (a[mid] == key)
    {
        if (mid > 0 && a[mid-1] != key || mid == 0)
        {
            return mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    else if (a[mid] > key)
    {
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }

    return GetFirstNumber(a, start, end, key);

}


int GetLastNumber(int *a, int start, int end, int key)
{
    int mid = (start + end) >> 1;

    if (a[mid] == key)
    {
        if (mid < end && a[mid+1] != key || mid == end)
        {
            return mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    else if (a[mid] > key)
    {
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }

    return GetLastNumber(a, start, end, key);
}

int GetNumberOfKey(int *a, int len, int key)
{
    if (a==NULL || len < 0)
        return 0;
    int FirstPos = GetFirstNumber(a, 0, len - 1, key);
    int LastPos = GetLastNumber(a, 0, len - 1, key);

    if (FirstPos > -1 && LastPos > -1)
    {
        int Count = LastPos - FirstPos + 1;
        return Count;
    }
    else{
        return 0;
    }
}

void main()
{
    int n, key;
    int a[100];
    int i;
    
    while (scanf("%d", &n) != EOF)
    {
        for (i=0; i<n; i++)
        {
            scanf("%d", a+i);
        }
        
        scanf("%d", &key);
        printf("key numbers is:%d\n", GetNumberOfKey(a, n, key));

    }
}
