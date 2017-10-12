#include<stdio.h>
void FindTwoNumSum(int *t, int len, int sum, int *a, int *b)
{
    if (len < 2)
    {
        printf("Input nums must gt > 2\n");
    }
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        int cur_sum = t[start] + t[end];
        if (cur_sum == sum)
        {
            *a = t[start];
            *b = t[end];
            printf("%d %d\n", *a, *b);
            start++;
            end--;
            continue;
        }

        if (cur_sum > sum)
        {
            end--;
        }
        else
        {
            start ++;
        }
    }
}


void main()
{
    int n, s;
    int t[100];
    int a, b;
    int i;

    while (scanf("%d %d", &n, &s) != EOF)
    {
        for (i=0; i<n; i++)
        {
            scanf("%d", t+i);
        }
        FindTwoNumSum(t, n, s, &a, &b);
    }
}
