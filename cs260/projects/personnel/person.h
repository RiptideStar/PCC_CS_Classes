#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//person class with encapsulated data
class person
{
private:
    char *ID;
    char *fName;
    char *lName;
    char *familyID;

public:
    //constructors
    person();
    person(char *initID, char *initFName, char *initLName, char *initFamilyID);

    //destructor
    ~person();

    //copy constructor and assignment operator
    person(const person &otherPerson);
    void operator=(const person &otherPerson);

    //accessors and mutators
    // void getID(char *targetID)const;
    char *getID() const;
    char *getFName() const;
    char *getLName() const;
    char *getFamilyID() const;
    void setID(char *newID);
    void setFName(char *newFName);
    void setLName(char *newLName);
    void setFamilyID(char *newFamilyID);

    //  print/output
    void print() const;
};

#endif