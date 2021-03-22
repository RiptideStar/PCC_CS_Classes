#ifndef BUILDER_H
#define BUILDER_H

#include "linkedList.h"
#include "stack.h"

class builder
{
    private:
        int id;
        int currentSector;
        linkedList taskList;
        stack route;

    public:
        //constructor
        builder();

        void setBuilderNum(int givenID);
        
        void addRequest(int sector, structure_type type);
        
        //return true if at least one builder did something
        bool doCycle();
        bool shouldMove(event e);

        void returnHome();
};


#endif 