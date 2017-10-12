#include<stdio.h>


typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *lchild;
    struct BinaryTreeNode *rchild;
}BTNode;


int TreeDepth(BTNode *root)
{
    if (root == NULL)
        return 0;

    int nleft = 1;
    int nright = 1;

    int nleft += TreeDepth(root->lchild);
    int nright += TreeDepth(root->rchild);

    return (nleft > nright)? nleft : nright;
}
