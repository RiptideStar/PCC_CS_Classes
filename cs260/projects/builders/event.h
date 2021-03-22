#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "structuretype.h"
using namespace std;

//Class that encapsulates event data
class event
{
private:
    int sector;
    structure_type buildingType;

public:
    //constructors
    event();
    event(int initSector, structure_type initType);
    //copy constructor
    event(event &otherEvent);
    //operator= overload
    void operator=(event &otherEvent);

    //setters and getters
    const int getSector();
    const structure_type getBuildingType();
    void getBuildingTypeString(char *str);
    void setSector(int newSector);
    void setBuildingType(structure_type newType);
    void setBuildingTypeString(char *str);

    //print
    void print()const;
};

#endif