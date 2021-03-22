#ifndef SURVEYDATA_H
#define SURVEYDATA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

//Class that encapsulates the survey data (sector, exposure, speed)
class surveyData
{
private:
    int sector;
    int exposure;
    int speed;

public:
    //constructors
    surveyData();
    surveyData(int initSector, int initExposure, int initSpeed);
    //copy constructor
    surveyData(surveyData &otherData);
    //operator= overload
    void operator=(surveyData &otherData);
    //no need of a destructor

    //Setters and Getters
    const int getSector();
    const int getExposure();
    const int getSpeed();
    void setSector(int newSector);
    void setExposure(int newExposure);
    void setSpeed(int newSpeed);

    //Print Function
    const void printSurveyDataToConsole();
};

#endif