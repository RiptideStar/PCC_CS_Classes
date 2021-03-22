#include "table.h"

void printExtreme(node *root, bool smallest)
{
    if (smallest)
    {
        if (root->left)
            printExtreme(root->left, smallest);
        else
            cout << root->data;
    }
    else
    {
        if (root->right)
            printExtreme(root->right, smallest);
        else
            cout << root->data;
    }
}

void copyOdd(node *root, node **newRoot)
{
    if (root->data % 2 != 0)
    {
        //initialize newRoot to contain the odd node from original root
        (*newRoot) = new node;
        (*newRoot)->data = root->data;
        (*newRoot)->left = NULL;
        (*newRoot)->right = NULL;
    }
    if (root->left)
    {
        //if newRoot is actually initialized, pass in the left version of the newRoot
        if (*newRoot)
            copyOdd(root->left, &((*newRoot)->left));
        //otherwise insert data still into newRoot    
        else
            copyOdd(root->left, newRoot);
    }
    if (root->right)
    {
        //if newRoot is actually initialized, pass in the right version of the newRoot
        if (*newRoot)
            copyOdd(root->right, &((*newRoot)->right));
        //otherwise insert data still into newRoot
        else
            copyOdd(root->right, newRoot);
    }
}