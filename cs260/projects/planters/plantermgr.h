#ifndef PLANTERMGR_H
#define PLANTERMGR_H

#include "BST.h"

class plantermgr
{
private:
    //bst
    BST bst;

public:
    void plant(int box, char* name);
    void harvest(char* name, int start, int end);
    void prune(int box);
};




#endif