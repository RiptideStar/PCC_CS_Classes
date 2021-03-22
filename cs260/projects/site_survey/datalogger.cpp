#include "datalogger.h"

//constructor makes a list
datalogger::datalogger()
{
    list = linkedList();
}

void datalogger::addData(int sector, int exposure, int speed)
{
    list.addANode(sector, exposure, speed);
}

void datalogger::removeSector(int sector)
{
    list.removeBySector(sector);
}

bool datalogger::containsSector(int sector)
{
    return list.containsSector(sector);
}

void datalogger::printReport()
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Data values" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Data by Sector" << endl;
    list.printDataValuesSector();
    cout << "Data by Exposure" << endl;
    list.printDataValuesExposure();
    cout << "Data by Speed" << endl;
    list.printDataValuesSpeed();

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Averages per sector" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    list.printAveragePerSector();

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Histogram data for exposure" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    list.printHistogramDataExposure();

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Histogram data for speed" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    list.printHistogramDataSpeed();
}

void datalogger::printSectorList()
{
    list.printSectorList();
}