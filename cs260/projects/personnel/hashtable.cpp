#include "hashtable.h"

hashtable::hashtable() : size(0), capacity(DEFAULT_CAPACITY)
{
    array = new node *[DEFAULT_CAPACITY];
    for (int i = 0; i < capacity; i++)
        array[i] = NULL;
}

hashtable::hashtable(const hashtable &other) : size(other.size), capacity(other.capacity)
{
    array = new node *[capacity];

    //copy tables
    for (int i = 0; i < capacity; i++)
    {
        if (other.array[i] == NULL)
        {
            array[i] == NULL;
        }
        else
        {
            array[i] = new node(other.array[i]->data);

            node *currentOther = other.array[i]->next;
            node *currentThis = array[i];

            while (currentOther)
            {
                //copy other data to this table's
                currentThis->next = new node(currentOther->data);
                //shift pointers forward
                currentThis = currentThis->next;
                currentOther = currentOther->next;
            }
            currentOther->next = NULL; //end of list
        }
    }
}

hashtable &hashtable::operator=(const hashtable &other)
{
    if (this == &other)
        return *this;
    else
    {
        destroy();

        //construct/initialize variables
        capacity = other.capacity;
        size = other.size;
        array = new node *[capacity];

        //perform loop to copy table
        for (int i = 0; i < capacity; i++)
        {
            if (other.array[i] == NULL)
            {
                array[i] == NULL;
            }
            else
            {
                array[i] = new node(other.array[i]->data);

                node *currentOther = other.array[i]->next;
                node *currentThis = array[i];

                while (currentOther)
                {
                    //copy other data to this table's
                    currentThis->next = new node(currentOther->data);
                    //shift pointers forward
                    currentThis = currentThis->next;
                    currentOther = currentOther->next;
                }
                currentOther->next = NULL; //end of list
            }
        }
        return *this;
    }
}

hashtable::~hashtable()
{
    destroy();
}

void hashtable::destroy()
{
    for (int i = 0; i < capacity; i++)
    {
        node *current = array[i];
        node *temp;
        while (current)
        {
            temp = current->next;
            current->next = NULL;
            delete current;
            current = temp;
        }
    }

    delete[] array;
}

void hashtable::insert(const person p)
{
    //get person ID (will be used for hash function)
    char *id = p.getID();
    //find an index for the node to go to
    int index = hashFunction(id);

    //new node with the person data
    node *newNode = new node(p);

    //increment array size if there wasn't a node already there
    if (!array[index])
    {
        size++;
    }

    //insert node into table
    newNode->next = array[index];
    array[index] = newNode;
}

//this hash function will take in the person's ID and sum up ascii values of the chars
int hashtable::hashFunction(char *id)
{
    //this is the number we will be us (try numbers from 3-71)
    int primeFactorForSpread = 17;

    char *c;

    int hash = 6;
    //traverse through the char* ID and change the hash value up with respect to the ascii character values
    for (c = id; *c != '\0'; c++)
    {
        //convert char to ascii int value
        int asciiChar = (int)*c;
        //change hash to its own current value multiplied by a prime factor added to the char value
        hash = hash * primeFactorForSpread + asciiChar;
    }

    //let's make sure hash is inside the capacity region of the table with modulo
    hash = hash % capacity;

    //our hash value is basically unique to the specific ID we have received and it is a number
    //that fits into our size constraints, let's use it!
    return hash;
}

person *hashtable::search(char *searchID)
{
    //find the index for the node to go to
    int index = hashFunction(searchID);

    node *head = array[index];
    char *currentID;
    while (head)
    {
        currentID = head->data.getID();
        // head->data.getID(currentID);
        if (strcmp(searchID, currentID) == 0)
        {
            // returnValue = head->data;
            // return;
            return &head->data;
        }
        else
            head = head->next;
    }
    return NULL;
}

int hashtable::getSize() const
{
    return size;
}

int hashtable::getCapacity() const
{
    return capacity;
}


//extra 
void hashtable::remove(char *idKey)
{
    //find index to remove at
    int index = hashFunction(idKey);

    node *head = array[index];
    node *previous = NULL;
    char *currentID;
    while (head)
    {
        currentID = head->data.getID();

        if (strcmp(idKey, currentID) == 0)
        {
            //have previous node link up to the node after the node we want to delete
            if (!previous)
            {
                array[index] = head->next;

                //if this slot of the array isn't taken anymore, decrement size
                if(array[index] == NULL)
                {
                    size--;
                }
            }
            else
                previous->next = head->next;

            head->next = NULL;
            delete head;
            return;    
        }
        else
        {
            //shift the pointers forward
            previous = head;
            head = head->next;
        }
    }
}