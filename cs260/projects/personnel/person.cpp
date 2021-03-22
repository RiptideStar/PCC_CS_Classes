#include "person.h"

person::person()
{
    ID = NULL;
    fName = NULL;
    lName = NULL;
    familyID = NULL;
}

person::person(char *initID, char *initFName, char *initLName, char *initFamilyID)
{
    ID = new char[strlen(initID) + 1];
    fName = new char[strlen(initFName) + 1];
    lName = new char[strlen(initLName) + 1];
    familyID = new char[strlen(initFamilyID) + 1];

    //initialize all values of the data
    strcpy(ID, initID);
    strcpy(fName, initFName);
    strcpy(lName, initLName);
    strcpy(familyID, initFamilyID);
}

person::person(const person &otherperson)
{
    ID = new char[strlen(otherperson.getID()) + 1];
    strcpy(ID, otherperson.getID());
    fName = new char[strlen(otherperson.getFName()) + 1];
    strcpy(fName, otherperson.getFName());
    lName = new char[strlen(otherperson.getLName()) + 1];
    strcpy(lName, otherperson.getLName());
    familyID = new char[strlen(otherperson.getFamilyID()) + 1];
    strcpy(familyID, otherperson.getFamilyID());
}

void person::operator=(const person &otherperson)
{
    if (ID)
        delete[] ID;
    if (fName)
        delete[] fName;
    if (lName)
        delete[] lName;
    if (familyID)
        delete[] familyID;

    ID = new char[strlen(otherperson.getID()) + 1];
    strcpy(ID, otherperson.getID());
    fName = new char[strlen(otherperson.getFName()) + 1];
    strcpy(fName, otherperson.getFName());
    lName = new char[strlen(otherperson.getLName()) + 1];
    strcpy(lName, otherperson.getLName());
    familyID = new char[strlen(otherperson.getFamilyID()) + 1];
    strcpy(familyID, otherperson.getFamilyID());
}

person::~person()
{
    delete[] ID;
    delete[] fName;
    delete[] lName;
    delete[] familyID;
}

char *person::getID() const
{
    return ID;
}
char *person::getFName() const
{
    return fName;
}
char *person::getLName() const
{
    return lName;
}
char *person::getFamilyID() const
{
    return familyID;
}

void person::setID(char *newID)
{
    strcpy(ID, newID);
}
void person::setFName(char *newFName)
{
    strcpy(fName, newFName);
}
void person::setLName(char *newLName)
{
    strcpy(lName, newLName);
}
void person::setFamilyID(char *newFamilyID)
{
    strcpy(familyID, newFamilyID);
}

void person::print() const
{
    cout << "ID: " << ID << endl;
    cout << "First Name: " << fName << endl;
    cout << "Last Name: " << lName << endl;
    cout << endl;
}