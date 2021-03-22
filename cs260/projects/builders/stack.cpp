#include "stack.h"

stack::stack()
{
    top = NULL;
}

stack::~stack()
{
    event e;
    while (!isEmpty())
    {
        pop(e);
    }
}

stack::stack(stack &other)
{
    if (!other.isEmpty())
    {
        //current contains top of other stack
        stackNode *current;
        other.getTop(current);
        top = current;
        current = current->next;

        stackNode *thisCurrent = top;

        while (current != NULL)
        {
            stackNode *newNode = new stackNode;
            newNode->data = current->data;
            newNode->next = NULL;
            thisCurrent->next = newNode;
            thisCurrent = newNode;
            current = current->next;
        }
    }
    else
    {
        top = NULL;
    }
}

void stack::operator=(stack &other)
{
    if (!other.isEmpty())
    {
        //current contains top of other stack
        stackNode *current;
        other.getTop(current);
        top = current;
        current = current->next;

        stackNode *thisCurrent = top;

        while (current != NULL)
        {
            stackNode *newNode = new stackNode;
            newNode->data = current->data;
            newNode->next = NULL;
            thisCurrent->next = newNode;
            thisCurrent = newNode;
            current = current->next;
        }
    }
    else
    {
        top = NULL;
    }
}

void stack::getTop(stackNode *&node)const
{
    node = top;
}

void stack::push(event e)
{
    //create new stackNode
    stackNode *temp = new stackNode;
    temp->data = e;

    //push it into list
    temp->next = top;
    top = temp;
}

//copy top into event e
void stack::peek(event &e)
{
    if (!isEmpty())
    {
        e = top->data;
    }

    //hopefully we never get into this part of the code...
    else
    {
        cout << "Nothing in stack to look at" << endl;
        exit(1);
    }
}

void stack::pop(event &e)
{
    //set temp to top and shift top
    stackNode *temp = top;
    top = top->next;
    e = temp->data;

    //deallocate top
    delete temp;
}

bool stack::isEmpty() const
{
    return top == NULL;
}