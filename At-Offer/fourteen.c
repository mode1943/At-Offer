#include<stdio.h>
#include<string.h>

void swap(char *str, int low, int high)
{
    char temp;
    temp = str[low];
    str[low] = str[high];
    str[high] = temp;
}

void ReverseStr(char *str, int low, int high)
{
    while (low < high)
    {
        swap(str, low, high);
        low++;
        high--;
    }
}

void RolString(char *str, int k)
{
    int len = strlen(str);
    k = k % len;

    ReverseStr(str, 0, k - 1);
    ReverseStr(str, k, len - 1);
    ReverseStr(str, 0, len - 1);
}

void main()
{
    int k;
    char str[50];
    
    while (scanf("%s %d", str, &k) != EOF)
    {
        RolString(str, k);
        puts(str);
    }
}
