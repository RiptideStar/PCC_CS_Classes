#include <iostream>
#include "list.h"

//recursively insert at head
void reverse(node *head, node *&newHead)
{
    //insert node at head
    node* newNode = new node;
    newNode->data = head->data;
    newNode->next = newHead;
    newHead = newNode;

    //base case, end of list
    if (head->next == NULL)
    {
        return;
    }

    //recursive call up until end of list
    reverse(head->next, newHead);
    
}

void removeLast(node *&head)
{
    if (head->next->next == NULL)
    {
        node* temp = head->next;
        head->next = NULL;
        delete temp;
        return;
    }
    removeLast(head->next);
}