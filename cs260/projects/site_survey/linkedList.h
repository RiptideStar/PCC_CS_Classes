#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "surveyData.h"

//struct for a node for the LL
struct dataNode
{
    surveyData data;

    dataNode *nextBySector;
    dataNode *nextByExposure;
    dataNode *nextBySpeed;

    dataNode *prevBySector;
    dataNode *prevByExposure;
    dataNode *prevBySpeed;
};

class linkedList
{
private:
    int maxSector;
    int maxExposure;
    int maxSpeed;
    dataNode *headBySector;
    dataNode *headByExposure;
    dataNode *headBySpeed;

public:
    //constructor
    linkedList();
    //destructor
    ~linkedList();

    //insertion
    bool addANode(int sector, int exposure, int speed); //the master insert function
    void insertBySector(dataNode *&newNode);             //The 3 insert functions per "thread"
    void insertByExposure(dataNode *&newNode);
    void insertBySpeed(dataNode *&newNode);

    //Output for Report
    const void printDataValuesSector();
    const void printDataValuesExposure();
    const void printDataValuesSpeed();
    const void printAveragePerSector();
    const void printHistogramDataExposure(); 
    const void printHistogramDataSpeed();    

    //Printing all the sectors
    const void printSectorList();

    //Deletion
    void removeBySector(int sector); //master remove function
    void modifyListForDeletionSector(dataNode *node); //the 3 (preparing for) remove functions per "thread"
    void modifyListForDeletionExposure(dataNode *node);
    void modifyListForDeletionSpeed(dataNode *node);
    bool containsSector(int sector);
};

#endif