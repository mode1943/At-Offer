#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void CreateLink(Node *L, int n)
{
    Node *T, *P;
    L->next = NULL;
    L->data = -1;
    T = L;
    int i;

    for (i=1; i<=n; i++)
    {
        P = (Node*)malloc(sizeof(Node));
        P->data = i;
        P->next = NULL;
        T->next = P;
        T = P;
    }
    T->next = L;
}

int FindLastOne(Node *L, int m, int n)
{
    if (m == 0 || L == NULL)
    {
        return -1;
    }
    
    Node *S, *M, *D;
    S = L;
    while (n > 1)
    {
        int i;
        for (i=1; i<m; i++)
        {
            if (S->next != L)
            {
                S = S->next;
            }
            else
            {
                S = S->next->next;
            }
        }

        Node *D;
        if (S->next == L)
        {
            D = L->next;
            L->next = D->next;
            free(D);
            S = L;
        }

        else if(S->next->next == L)
        {
            D = S->next;
            S->next = L;
            free(D);
            S = L; 
        }

        else
        {
            D = S->next;
            S->next = D->next;
            free(D);
        }
        n--;
    }
    return S->next->data;

    
}

void PrintLink(Node *L)
{
    Node *P, *M;
    
    M = L;
    while (M->next != L)
    {
        P = M->next;
        printf("%d\n", P->data);
        M = P;
    }
}

void main()
{
    int n, m;
    Node *L, *Test;
    L = (Node*)malloc(sizeof(Node));
    
    while(scanf("%d %d", &n, &m) != EOF)
    {
        CreateLink(L, n);
        //PrintLink(L);
        printf("%d\n", FindLastOne(L, m, n));
    }
    
}
