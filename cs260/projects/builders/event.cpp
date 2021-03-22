#include "event.h"

event::event()
{
    sector = 0;
    buildingType = getFromString("UNK");
}

event::event(int initSector, structure_type initType)
{
    sector = initSector;
    buildingType = initType;
}

event::event(event &otherEvent)
{
    sector = otherEvent.getSector();
    buildingType = otherEvent.getBuildingType();
}

void event::operator=(event &otherEvent)
{
    sector = otherEvent.getSector();
    buildingType = otherEvent.getBuildingType();
}

const int event::getSector()
{
    return sector;
}

const structure_type event::getBuildingType()
{
    return buildingType;
}

void event::getBuildingTypeString(char *str)
{
    toString(buildingType, str);
}

void event::setSector(int newSector)
{
    sector = newSector;
}

void event::setBuildingType(structure_type newType)
{
    buildingType = newType;
}

void event::setBuildingTypeString(char *str)
{
    buildingType = getFromString(str);
}

//water harvester at sector #
//solar energy collector at sector #
//wind turbine at sector #
void event::print()const
{
    if (buildingType == SOLAR)
        cout << "solar energy collector in sector " << sector << endl;
    else if (buildingType == WIND)
        cout << "wind turbine in sector " << sector << endl;
    else
        cout << "water harvester in sector " << sector << endl;
}