#include<stdio.h>
#include<stdbool.h>

typedef struct BTNode
{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;

}BTNode, *BTree;

bool IsBalancedTree(BTree ptree, int *depth)
{
    if (ptree == NULL)
    {
        *depth = 0;
        return True;
    }

    int left = 0;
    int right = 0;
    if (IsBalancedTree(ptree->lchild, &left) && IsBalancedTree(ptree->rchild, &right))
    {
        int diff = left - right;
        if (diff <= 1 || diff <= -1)
        {
            *depth = 1 + ((left > right) ? left : right);
            return True;
        }
    }

    return False;
}


bool IsBalanced(BTree ptree)
{
    int depth = 0;
    return IsBalancedTree(ptree, &depth);
}



