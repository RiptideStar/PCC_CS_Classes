#include "personmgr.h"

// personmgr::personmgr()
// {

// }

void personmgr::addPerson(const person &p)
{
    htable.insert(p);
}

const person *personmgr::findPerson(char *searchID)
{
    const person *pRet = htable.search(searchID);
    return pRet;
}

void personmgr::printHtStats() const
{
    cout << "Table uses " << htable.getSize() << " out of " << htable.getCapacity() << " entries." << endl << endl;
}



//extra
void personmgr::removePerson(char* searchID)
{
    htable.remove(searchID);
}