#include "table.h"

//Please put the implementation of the required functions here

int countNodes(node *root)
{
    int count = 1;
    //if there is a left node, go and traverse thru
    if (root->left)
        count += countNodes(root->left);

    //if there is a right node, go and traverse thru
    if (root->right)
        count += countNodes(root->right);

    //at this point, we return how many nodes are below this current node
    return count;
}

int sumLeaves(node *root)
{
    int count = 0;

    //base case is finding a leaf, then we return 1 if leaf
    if (root->left == NULL && root->right == NULL)
    {
        count = root->data;
    }
    //otherwise look into the subtrees and sum up their leaves   
    else
    {
        if (root->left)
            count += sumLeaves(root->left);
        if (root->right)
            count += sumLeaves(root->right);
    }

    //at this point, we return the amount of leaves below this node
    return count;
}