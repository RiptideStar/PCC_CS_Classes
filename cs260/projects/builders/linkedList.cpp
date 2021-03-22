#include "linkedList.h"

linkedList::linkedList()
{
    head = NULL;
    tail = NULL;
}

linkedList::~linkedList()
{
    //if there is a list
    if (head)
    {
        node *current = head;
        //delete everything going up until final element
        while (current->next != NULL)
        {
            node *temp = current;
            current = current->next;
            delete temp;
        }
        //final element deletion
        delete current;
    }
}

linkedList::linkedList(linkedList &other)
{
    if (!other.isEmpty())
    {
        node *current;
        other.getHeadNode(current);
        while (current != NULL)
        {
            addEvent(current->data);
            current = current->next;
        }
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}

void linkedList::operator=(linkedList &other)
{
    if (!other.isEmpty())
    {
        node *current;
        other.getHeadNode(current);
        while (current != NULL)
        {
            addEvent(current->data);
            current = current->next;
        }
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}

//adds event at tail end
void linkedList::addEvent(event e)
{
    node *newNode = new node;
    newNode->data = e;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

//parameter is the event that we will return the tail into
//removes from the head end (which is opposite from inserting at tail end)
void linkedList::removeHead(event &e)
{
    node *temp = head;
    e = temp->data;
    head = head->next;
    delete temp;
}

//returns head into event e
void linkedList::getHeadNode(node *&e)const
{
    e = head;
}

bool linkedList::isEmpty()
{
    return head == NULL;
}