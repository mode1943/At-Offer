#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void FindContinousSequence(int s)
{
    int start =  1;
    int end = 2;
    int middle = (1 + s)>>1;
    int cursum = start + end;
    int i;
    bool can = false;

    while (start < middle)
    {
        
        if (cursum == s)
        {
            can = true;
            for (i=start; i<=end; i++)
            {
                if (i == end)
                {
                    printf("%d\n", i);
                }
                else
                {
                    printf("%d ", i);
                }
            }
            end++;
            cursum += end;
        }
        
        if (cursum < s)
        {
            end++;
            cursum += end;
        }
        else if (cursum > s)
        {
            cursum -= start;
            start++;
        }
    }
    if (!can)
    {
        printf("Pity!\n");        
    }

}

void main()
{
    int s;

    while(scanf("%d", &s) != EOF)
    {
        FindContinousSequence(s);
    }
}
