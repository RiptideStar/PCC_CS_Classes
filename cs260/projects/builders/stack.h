#ifndef STACK_H
#define STACK_H

#include "event.h"
struct stackNode
{
    event data;
    stackNode *next;
};
class stack
{   
    private:
        stackNode *top;
    
    public:
        //constructor
        stack();
        //destructor
        ~stack();

        //copy constructor and assignment operator overload
        stack(stack &other);
        void operator=(stack &other);

        //return top node (similar to peek)
        void getTop(stackNode *&node)const;

        void push(event e);
        bool isEmpty()const;
        void pop(event &e);
        void peek(event &e);
};

#endif