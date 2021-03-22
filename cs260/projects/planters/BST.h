#ifndef BST_H
#define BST_H

#include "plant.h"

class BST
{
public:
    //bst functions
    BST();
    BST(const BST &otherBST);
    void operator=(const BST &otherBST);
    ~BST();

    void insert(int boxNum, char *name);
    void printBoxesInRange(char *keyName, int min, int max);
    void remove(int boxNum);

private:
    struct node
    {
        plant data;
        node *left;
        node *right;
        node(int initBox, char *initType) : data(initBox, initType), left(NULL), right(NULL)
        {
        }
    };

    node *root;

    void copy(node *&destRoot, node *srcRoot);
    void deallocate(node *&root);

    node* insertR(int boxNum, char *name, node *&root);
    void printBoxesInRangeR(char *keyName, int min, int max, node *&root);
    void removeR(int boxNum, node *&root);
};

#endif