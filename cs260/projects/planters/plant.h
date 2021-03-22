#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class plant
{
private:
    int box;
    char *plantType;

public:
    //constructors
    plant();
    plant(int initBox, char* initType);
    plant(const plant &otherPlant);
    
    void operator=(const plant &otherPlant);

    ~plant();
    
    //setters and getters
    int getBox();
    char* getPlantType();
    void setBox(int newBox);
    void setPlantType(char* newType);

    void print();
};

#endif