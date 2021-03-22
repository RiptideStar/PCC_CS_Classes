#include "table.h"

//Please put the impelementation of the required functions here
int sumOfNodes(node *root)
{
    int sum = 0;

    if (root->left)
        sum += sumOfNodes(root->left);
    if (root->right)
        sum += sumOfNodes(root->right);

    sum += root->data;
    return sum;
}

void copyLeaf(node *src, node *&dest)
{
    if (src->left == NULL && src->right == NULL)
    {
        if (!dest)
        {
            dest = new node;
            dest->data = src->data;
            dest->left = NULL;
            dest->right = NULL;
            return;
        }
        else if (src->data < dest->data)
            copyLeaf(src, dest->left);
        else
            copyLeaf(src, dest->right);
    }
    else
    {
        if (src->left)
            copyLeaf(src->left, dest);
        if (src->right)
            copyLeaf(src->right, dest);
    }
}
