#include "BST.h"

BST::BST() : root(NULL)
{
}

BST::BST(const BST &otherBST)
{
    copy(root, otherBST.root);
}

//deep copy
void BST::copy(node *&destRoot, node *srcRoot)
{
    if (srcRoot)
    {
        destRoot = new node(srcRoot->data.getBox(), srcRoot->data.getPlantType());

        //traverse thru left and right subtrees
        copy(destRoot->left, srcRoot->left);
        copy(destRoot->right, srcRoot->right);
    }
    else
    {
        //time for a leaf to bloom
        destRoot = NULL;
    }
}

void BST::operator=(const BST &otherBST)
{
    //deallocate whatever is inside tree already
    deallocate(root);
    //then perform deep copy
    copy(root, otherBST.root);
}

void BST::deallocate(node *&root)
{
    //post order traversal
    if (root)
    {
        deallocate(root->left);
        deallocate(root->right);
        delete root;
        root = NULL;
    }
}

BST::~BST()
{
    deallocate(root);
}

void BST::insert(int boxNum, char *name)
{
    // root = insertR(boxNum, name, root);
    if (!root)
        root = insertR(boxNum, name, root);
    else
    {
        insertR(boxNum, name, root);
    }
}

BST::node *BST::insertR(int boxNum, char *name, node *&root)
{
    node *newNode = new node(boxNum, name);

    //current node and node before current
    node *curr = root;
    node *before = NULL;

    //iterate to find node to insert at
    while (curr)
    {
        before = curr;
        if (boxNum < curr->data.getBox())
            curr = curr->left;
        else
            curr = curr->right;
    }

    //check if there is a list
    if (before == NULL)
        before = newNode;

    //otherwise, let's stick this node in the right place according to value
    else if (boxNum < before->data.getBox())
        before->left = newNode;
    else
        before->right = newNode;

    return before;
}

void BST::printBoxesInRange(char *keyName, int min, int max)
{
    printBoxesInRangeR(keyName, min, max, root);
}

void BST::printBoxesInRangeR(char *keyName, int min, int max, node *&root)
{
    //for in order printing, we do inorder traversal

    //if we find a box inside range (non-inclusive)
    if (root->data.getBox() < max && root->data.getBox() > min)
    {
        //since this box is inside range (non-inclusive), we have to search left and right if they exist
        if (root->left)
            printBoxesInRangeR(keyName, min, max, root->left);

        //compare type to see if we should print
        if (strcmp(keyName, root->data.getPlantType()) == 0)
            cout << root->data.getBox() << " "; //cout << root->data.getBox() << " "; cout << " " << root->data.getBox()

        if (root->right)
            printBoxesInRangeR(keyName, min, max, root->right);
    }
    //compare box value to see if it is less or equal to min
    else if (root->data.getBox() <= min)
    {
        //since it is possible for box value to equal to min, we have to check if we can print it
        if (root->data.getBox() == min && strcmp(keyName, root->data.getPlantType()) == 0)
            cout << root->data.getBox() << " ";

        //we only have to search right subtree if box value is <= min!
        if (root->right)
            printBoxesInRangeR(keyName, min, max, root->right);
    }
    //box value must be greater or equal to max
    else
    {
        //we only have to search left subtree if box value is >= max!
        if (root->left)
            printBoxesInRangeR(keyName, min, max, root->left);

        //since it is possible for box value to equal to max, we have to check if we can print it
        if (root->data.getBox() == max && strcmp(keyName, root->data.getPlantType()) == 0)
            cout << root->data.getBox() << " ";
    }
}

void BST::remove(int boxNum)
{
    removeR(boxNum, root);
}

void BST::removeR(int boxNum, node *&root)
{
    //base case
    if (root == NULL)
    {
        //well, we didn't find it, so let's not do anything
    }
    else if (boxNum == root->data.getBox())
    {
        // we have found our node to delete! //

        //case 1: leaf
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2: one child: right
        else if (!root->left)
        {
            node *temp = root;

            //have pointer point to right node
            root = root->right;

            temp->right = NULL;
            delete temp;
        }
        //case 3: one child: left
        else if (!root->right)
        {
            node *temp = root;

            //have pointer point to left node
            root = root->left;

            temp->left = NULL;
            delete temp;
        }
        //case 4: root has two children
        else
        {
            //let's find the inorder successor
            node *inOrderSuccessor = root->right;
            node* parent = NULL;
            while (inOrderSuccessor->left)
            {
                parent = inOrderSuccessor;
                inOrderSuccessor = inOrderSuccessor->left;
            }

            root->data = inOrderSuccessor->data;

            // if inorder successor is root->right
            if (parent == NULL)
                root->right = inOrderSuccessor->right;
            //otherwise, replace the parent pointer to inOrder successor to its right node (which might exist)
            else
                parent->left = inOrderSuccessor->right;    

            inOrderSuccessor->right = NULL;
            delete inOrderSuccessor;    
        }
    }

    //keep searching for the node
    else if (boxNum < root->data.getBox())
        removeR(boxNum, root->left);
    else
        removeR(boxNum, root->right);
}