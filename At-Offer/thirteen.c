#include<stdio.h>

void swap(char *str, int begin, int end)
{
    char temp;
    temp = str[begin];
    str[begin] = str[end];
    str[end] = temp;
}

void swap_str(char *str, int begin, int end)
{
    while (begin < end)
    {
        swap(str, begin, end);
        begin++;
        end--;
    }
}

void ReverseSentence(char *str)
{
    int begin = 0;
    int end = 0;

    while (str[end] != '\0')
    {
        end++;
    }
    swap_str(str, 0, end-1);
    
    end = begin;
    while (str[end] != '\0')
    {
        while (str[end] != ' ')
        {
            end++;
        } 
        swap(str, begin, end - 1);
        puts(str);        
        while (str[end] == ' ')
        {
            end++;
        }

        begin = end;
    }
}


void main()
{
    char str[50000];

    while (gets(str) != NULL)
    {
        ReverseSentence(str);
        puts(str);
    }
}
