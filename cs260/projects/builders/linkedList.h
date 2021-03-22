#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "event.h"

struct node
{
    event data;
    node *next;
};

//insert at front and remove from back
class linkedList
{
private:
    node *head;
    node *tail;

public:
    //constructor
    linkedList();
    //destructor
    ~linkedList();

    //copy constructor and assignment operator overload
    linkedList(linkedList &other);
    void operator=(linkedList &other);

    //returns head
    void getHeadNode(node *&e)const;

    //NOTE: insertion and deletion at separate ends
    //implemented like a queue: first in first out
    //insertion at tail; deletion at head

    //insertion at tail
    void addEvent(event e);
    //removing at the head when builder starts doing the task
    void removeHead(event &e);

    bool isEmpty();
};
#endif