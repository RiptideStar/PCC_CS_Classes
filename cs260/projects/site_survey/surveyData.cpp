#include "surveyData.h"

//default constructor
surveyData::surveyData()
{
    sector = 0;
    exposure = 0;
    speed = 0;
}

//constructor with parameters
surveyData::surveyData(int initSector, int initExposure, int initSpeed)
{
    sector = initSector;
    exposure = initExposure;
    speed = initSpeed;
}

//copy constructor
surveyData::surveyData(surveyData &otherData)
{
    sector = otherData.getSector();
    exposure = otherData.getExposure();
    speed = otherData.getSpeed();
}
//assignment operator
void surveyData::operator=(surveyData &otherData)
{
    sector = otherData.getSector();
    exposure = otherData.getExposure();
    speed = otherData.getSpeed();
}

//accessors and mutators
const int surveyData::getSector()
{
    return sector;
}
const int surveyData::getExposure()
{
    return exposure;
}
const int surveyData::getSpeed()
{
    return speed;
}
void surveyData::setSector(int newSector)
{
    sector = newSector;
}
void surveyData::setExposure(int newExposure)
{
    exposure = newExposure;
}
void surveyData::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

//print function
//template: Sector: #<num> <exposure>% exposure, <speed> km/hr windspeed
const void surveyData::printSurveyDataToConsole()
{
    cout << "Sector: #" << sector << " " << exposure << "% exposure, " << speed << " km/hr windspeed" << endl;
}