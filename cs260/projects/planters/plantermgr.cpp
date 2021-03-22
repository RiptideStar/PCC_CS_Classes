#include "plantermgr.h"

void plantermgr::plant(int box, char* name)
{
    bst.insert(box, name);
    cout << "Planting " << name << " in box " << box << endl;
}

void plantermgr::harvest(char* name, int start, int end)
{
    cout << "Harvesting " << name << " from boxes " << start << " to " << end << ". The following boxes will be harvested: ";
    bst.printBoxesInRange(name, start, end);
    cout << endl << endl;
}

void plantermgr::prune(int box)
{
    cout << "Pruning box number " << box << "." << endl;
    bst.remove(box);
}