#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "linkedList.h"

class datalogger
{
private:
    linkedList list;

public:
    //constructor
    datalogger();
    
    void addData(int sector, int exposure, int speed);
    void removeSector(int sector);
    bool containsSector(int sector);
    void printReport();
    void printSectorList();
};

#endif