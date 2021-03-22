#include "dlist.h"

//put the implementation of the required functions here
void printNth(node *head, int n)
{
    if (n == 0) //base case: when we get to the node that we want to print
    {
        cout << head->data << endl;
    }
    else
    {
        if (head->next) //"shrink the list"
            printNth(head->next, n - 1);
        else //end of list, so let's print the last node
            printNth(head, 0);
    }
}

void insertAtN(node *&head, int n, int value)
{
    //end of list special case
    if (!head->next)
    {
        //create node
        node *newNode = new node;
        newNode->data = value;

        //linking node into the list
        head->next = newNode;
        newNode->previous = head;
        return;
    }

    //base case
    if (head->next && n == 0)
    {
        //create node
        node *newNode = new node;
        newNode->data = value;

        
        newNode->next = head;


        if (head->previous)
        {
            newNode->previous = head->previous;
            node * previousNode = head->previous;
            previousNode->next = newNode;
            //pointers shifted!
            head->next->previous = newNode;
        }
        else
        {
            head->previous = newNode;
        }
        //head to this node, since pointers shifted
        head = newNode;
        return;    
    }

    return insertAtN(head->next, n-1, value);
}