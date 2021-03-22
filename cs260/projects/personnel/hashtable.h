#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "person.h"

//hashtable data structure for data storage
class hashtable
{
private:
    struct node
    {
        person data;
        node *next;
        node(const person &p) : data(p), next(NULL)
        {
        }
    };
    //array of linked list heads: aka the table
    node **array;
    const static int DEFAULT_CAPACITY = 9973;
    int capacity;
    //size isn't amount of entries in the hash table, but rather how many slots of the array we are using
    int size;

public:
    hashtable();

    //copy constructor and assignment operator
    hashtable(const hashtable &other);
    hashtable &operator=(const hashtable &other);

    //destructor
    ~hashtable();
    void destroy();

    //functions for the hashtable
    int hashFunction(char *id);
    void insert(const person p);
    // void search(char *id, person &returnValue);
    person* search(char *searchID);
    void remove(char *idKey);
    int getSize() const;
    int getCapacity() const;
};

#endif