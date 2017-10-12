#include<stdio.h>
#include<stdbool.h>

bool IsValid;

int StrToInt(const char *str)
{
    int num = 0;
    bool IsMinus = false;
    if (str == NULL)
    {
        IsValid = false;
        return IsValid;
    }

    while (*str == ' ')
    {
        str++;
    }

    if (*str == '+')
    {
        str++;
    }
    else if (*str == '-')
    {
        str++;
        IsMinus = true;
    }

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
        {
            IsValid = false;
            return IsValid;
        }

        num = num * 10 + (*str - '0');
        str++;
    }

    num = IsMinus ? (-1 * num):num;
    return num;
}

void main()
{
    char str[100];
    scanf("%s", str);
    int num = StrToInt(str);
    printf("%d\n", num);

}
