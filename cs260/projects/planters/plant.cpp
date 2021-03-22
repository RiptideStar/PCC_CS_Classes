#include "plant.h"

plant::plant() : box(0), plantType(NULL)
{
}

plant::plant(int initBox, char *initType) : box(initBox)
{
    plantType = new char[strlen(initType) + 1];
    strcpy(plantType, initType);
}

plant::plant(const plant &otherPlant) : box(otherPlant.box)
{
    plantType = new char[strlen(otherPlant.plantType) + 1];
    strcpy(plantType, otherPlant.plantType);
}

void plant::operator=(const plant &otherPlant)
{
    box = otherPlant.box;

    if (plantType)
        delete[] plantType;
    plantType = new char[strlen(otherPlant.plantType) + 1];
    strcpy(plantType, otherPlant.plantType);
}

plant::~plant()
{
    delete [] plantType;
}

int plant::getBox()
{
    return box;
}

char *plant::getPlantType()
{
    return plantType;
}

void plant::setBox(int newBox)
{
    box = newBox;
}

void plant::setPlantType(char *newType)
{
    strcpy(plantType, newType);
}

void plant::print()
{
    cout << plantType << " in box " << box;
}