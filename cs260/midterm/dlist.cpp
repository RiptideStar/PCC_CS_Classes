#include "dlist.h"

int countEven(node *head)
{
    int count = 0;
    if (head->data % 2 == 0)
    {
        count++;
    }
    if (head->next == NULL)
    {
        return count;
    }
    count += countEven(head->next);
    return count;
}

int removeEven(node *&head)
{
    int count = 0;
    if (head->next == NULL)
    {
        if (head->data % 2 == 0)
        {
            count++;
            //delete
            node *temp = head;
            head->previous->next = NULL;
            delete temp;
            // head->previous->next = NULL;
            // delete head;
        }
        return count;
    }
    count += removeEven(head->next);
    if (head->data % 2 == 0)
    {
        count++;
        //delete
        node *current = head;

        if (head->next)
            head->next->previous = head->previous;
        if (head->previous == NULL)
        {
            head = head->next;
            // delete current;
            // return count;
        }
        else
            head->previous->next = head->next;
        delete current;
    }
    return count;
}