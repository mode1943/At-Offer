#include<stdio.h>

int hashtable[256];

void InitHashTable(char *str)
{
    int index;
    memset(str, 0, sizeof(hashtable));
    while (*str != '\0')
    {
        if (*str >= 0)
        {
            index = *str;
        }
        else
        {
            index = *str + 256;
        }

        hashtable[index] += 1;
    }
}

int GetFirstCharPos(char *str)
{
    int index;
    int count = 0;
    while (*str != '\0')
    {
        if (*str >= 0)
        {
            index = *str;
        }
        else
        {
            index = *str + 256;
        }

        if (hashtable[index] > 1)
        {
            ++str;
            count++;
        }
        else
        {
            return count++;
        }
    }
}

void main()
{
    char str[1000];

    while (gets(str) != NULL)
    {
        InitHashTable(str);
        printf("the first char pos:%d\n", GetFirstCharPos(str));
    }
}
