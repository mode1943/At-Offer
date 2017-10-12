#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 *
 *
 *题目描述：
 *输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 输入：
 输入可能包含多个测试样例。
 对于每个测试案例，输入的第一行为一个整数m (1<=m <=100)代表输入的正整数的个数。
 输入的第二行包括m个正整数，其中每个正整数不超过10000000。
 输出：
 对应每个测试案例，
 输出m个数字能排成的最小数字。
 样例输入：
 3
 23 13 6
 2
 23456 56
 样例输出：
 13236
 2345656
 *
 *
 */

char data[100][10];

int compare(const void *a, const void *b)
{
    char *str1 = (char *)a;
    char *str2 = (char *)b;
    char s1[20], s2[20];
    sprintf(s1, "%s%s", str1, str2);
    sprintf(s2, "%s%s", str2, str1);

    return strcmp(s1, s2);
}

void PrintMinNum(int *num, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        sprintf(data[i], "%d", num[i]);
    }

    qsort(data, n, sizeof(char)*10, compare);

    for (i=0; i<n; i++)
    {
        printf("%s", data[i]);
    }
    printf("\n");
}

void main()
{
    int i,n;
    int num[10];
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++)
    {
        scanf("%d", num + i);
    }
    
    PrintMinNum(num, n);
}

