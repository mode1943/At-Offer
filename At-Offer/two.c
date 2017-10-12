#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode
{
    int data;
    struct Tnode *lchild;
    struct Tnode *rchild;
}Tnode, *BiTree;

void CreateBiTree(BiTree *T)
{
    int vdata;
    scanf("%d", &vdata);
    
    if (vdata == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(Tnode));
        if (!T)
        {
            exit(EXIT_FAILURE);
        }
        (*T)->data = vdata;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int GetPreTraversePath(BiTree T, int val, int index, int *path, int *len)
{
    if (T == NULL)
    {
        *len = 0;
        return 0;
    }
    path[index] = T->data;
    if (T->data == val)
    {
        *len = index + 1;
        return 1;
    }
    else
    {
        int can = GetPreTraversePath(T->lchild, val, index+1, path, len);
        if (!can)
        {
            can = GetPreTraversePath(T->rchild, val, index+1, path, len);
        }
        return can;
    }
}

int GetLowCommonNode(int *path1, int *path2, int len1, int len2)
{
    int len = (len1 < len2)? len1:len2;
    int i;

    for (i=0; i<len; i++)
    {
        if (path1[i] != path2[i])
        {
            break;
        }
    }
    return  path1[i-1];
}

void main()
{
    int n;
    int node1, node2;
    int len1, len2;
    int path1[1000];
    int path2[1000];
    int can1, can2;
    BiTree T;

    while (scanf("%d", &n)!=EOF)
    {
        int i;
        for (i=0; i<n; i++)
        {
            T = NULL;
            printf("create binary tree:\n");
            CreateBiTree(&T);
            
            printf("Input two unchecked number:\n");
            scanf("%d %d", &node1, &node2);
            can1 = GetPreTraversePath(T, node1, 0, path1, &len1);
            can2 = GetPreTraversePath(T, node2, 0, path2, &len2);
            
            if (can1 && can2)
            {
                printf("The Low common node is:%d\n", GetLowCommonNode(path1, path2, len1, len2));
            }
            else
            {
                printf("My God\n");
            }
        }
    }

}
