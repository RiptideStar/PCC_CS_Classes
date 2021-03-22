#ifndef PERSONMGR_H
#define PERSONMGR_H

#include "hashtable.h"

//manages the hashtable
class personmgr
{
private:
    hashtable htable;
public:
    // personmgr();
    void addPerson(const person &p);
    const person* findPerson(char* searchID);
    void printHtStats()const;

    //extra
    void removePerson(char* searchID);
};

#endif