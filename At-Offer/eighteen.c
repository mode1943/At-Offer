#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool hashtable[256];

void InitHashTable(char *substr)
{
    memset(hashtable, false, sizeof(hashtable));

    while (*substr != '\0')
    {
        int index;
        if (*substr >= 0)
        {
            index = *substr;
        }
        else
        {
            index = *substr + 256;
        }
        hashtable[index] = true;
        ++substr;
    }
}

void DeleteChar(char *str)
{
    char *FastC = str;
    char *SlowC = str;
    int index;

    while (*FastC != '\0')
    {
        if (*FastC >= 0)
        {
            index = *FastC;
        }
        else
        {
            index = *FastC + 256;
        }

        if (hashtable[index] != true)
        {
            *SlowC = *FastC;
            SlowC++;
        }
        FastC++;
    }
    *SlowC = '\0';
}



void main()
{
    char Str[] = "this is a test";
    char SubStr[] = "tie";
    InitHashTable(SubStr);
    DeleteChar(Str);
    puts(Str);
}
