#include "linkedList.h"

//constructor
linkedList::linkedList()
{
    headBySector = NULL;
    headByExposure = NULL;
    headBySpeed = NULL;
    maxSector = 0;
    maxExposure = 0;
    maxSpeed = 0;
}

//destructor
linkedList::~linkedList()
{
    //if there is a list
    if (headBySector)
    {
        dataNode *current = headBySector;
        //delete everything going up until final element
        while (current->nextBySector != NULL)
        {
            dataNode *temp = current;
            current = current->nextBySector;
            delete temp;
        }
        //final element deletion
        delete current;
    }
}

bool linkedList::addANode(int sector, int exposure, int speed)
{
    //allocate and create the node
    dataNode *newNode = new dataNode;
    newNode->data.setSector(sector);
    newNode->data.setExposure(exposure);
    newNode->data.setSpeed(speed);
    newNode->nextBySector = NULL;
    newNode->nextByExposure = NULL;
    newNode->nextBySpeed = NULL;
    newNode->prevBySector = NULL;
    newNode->prevByExposure = NULL;
    newNode->prevBySpeed = NULL;

    //put the node into the list
    insertBySector(newNode);
    insertByExposure(newNode);
    insertBySpeed(newNode);

    return true;
}

//the three insert functions for the triply threaded linked list
void linkedList::insertBySector(dataNode *&newNode)
{
    // if there isn't a list
    if (headBySector == NULL)
        headBySector = newNode;

    // if the node is to be inserted at the beginning
    else if (headBySector->data.getSector() >= newNode->data.getSector())
    {
        newNode->nextBySector = headBySector;
        newNode->nextBySector->prevBySector = newNode;
        headBySector = newNode;
    }

    //now we need to find the node that we will insert after
    else
    {
        dataNode *current = headBySector;

        // find the node after which the new node is to be inserted
        while (current->nextBySector != NULL && current->nextBySector->data.getSector() < newNode->data.getSector())
            current = current->nextBySector;

        newNode->nextBySector = current->nextBySector;

        // we need to make this connection back to the node if there is a node after
        if (current->nextBySector != NULL)
            newNode->nextBySector->prevBySector = newNode;

        current->nextBySector = newNode;
        newNode->prevBySector = current;
    }

    // if new node is at the end, set it to max sector
    if (newNode->nextBySector == NULL)
    {
        maxSector = newNode->data.getSector(); //set max sector to the new end of the head
    }
}

void linkedList::insertByExposure(dataNode *&newNode)
{
    // if there isn't a list
    if (headByExposure == NULL)
        headByExposure = newNode;

    // if the node is to be inserted at the beginning
    else if (headByExposure->data.getExposure() >= newNode->data.getExposure())
    {
        newNode->nextByExposure = headByExposure;
        newNode->nextByExposure->prevByExposure = newNode;
        headByExposure = newNode;
    }

    //now we need to find the node that we will insert after
    else
    {
        dataNode *current = headByExposure;

        // find the node after which the new node is to be inserted
        while (current->nextByExposure != NULL && current->nextByExposure->data.getExposure() < newNode->data.getExposure())
            current = current->nextByExposure;

        newNode->nextByExposure = current->nextByExposure;

        // if the new node is not inserted at the end of the list
        if (current->nextByExposure != NULL)
            newNode->nextByExposure->prevByExposure = newNode;

        current->nextByExposure = newNode;
        newNode->prevByExposure = current;
    }

    // if new node is at the end, set it to max Exposure
    if (newNode->nextByExposure == NULL)
    {
        maxExposure = newNode->data.getExposure(); //set max exposure to the new end of the head
    }
}

void linkedList::insertBySpeed(dataNode *&newNode)
{
    // if there isn't a list
    if (headBySpeed == NULL)
        headBySpeed = newNode;

    // if the node is to be inserted at the beginning
    else if (headBySpeed->data.getSpeed() >= newNode->data.getSpeed())
    {
        newNode->nextBySpeed = headBySpeed;
        newNode->nextBySpeed->prevBySpeed = newNode;
        headBySpeed = newNode;
    }

    //now we need to find the node that we will insert after
    else
    {
        dataNode *current = headBySpeed;

        // locate the node after which the new node is to be inserted
        while (current->nextBySpeed != NULL && current->nextBySpeed->data.getSpeed() < newNode->data.getSpeed())
            current = current->nextBySpeed;

        newNode->nextBySpeed = current->nextBySpeed;

        // if the new node is not inserted
        // at the end of the list
        if (current->nextBySpeed != NULL)
            newNode->nextBySpeed->prevBySpeed = newNode;

        current->nextBySpeed = newNode;
        newNode->prevBySpeed = current;
    }

    // if new node is at the end, set it to max Speed
    if (newNode->nextBySpeed == NULL)
    {
        maxSpeed = newNode->data.getSpeed(); //set max Speed to the new end of the head
    }
}

const void linkedList::printDataValuesSector()
{
    //if head exists
    if (headBySector)
    {
        dataNode *current = headBySector;
        current->data.printSurveyDataToConsole();
        //traverse thru list and print the data
        while (current->nextBySector != NULL)
        {
            current = current->nextBySector;
            current->data.printSurveyDataToConsole();
        }
    }
    else
    {
        cout << "There aren't data values to print!" << endl;
    }
}

const void linkedList::printDataValuesExposure()
{
    //if head exists
    if (headByExposure)
    {
        dataNode *current = headByExposure;
        current->data.printSurveyDataToConsole();
        //traverse thru list and print the data
        while (current->nextByExposure != NULL)
        {
            current = current->nextByExposure;
            current->data.printSurveyDataToConsole();
        }
    }
    else
    {
        cout << "There aren't data values to print!" << endl;
    }
}

const void linkedList::printDataValuesSpeed()
{
    //if head exists
    if (headBySpeed)
    {
        dataNode *current = headBySpeed;
        current->data.printSurveyDataToConsole();
        //traverse thru list and print the data
        while (current->nextBySpeed != NULL)
        {
            current = current->nextBySpeed;
            current->data.printSurveyDataToConsole();
        }
    }
    else
    {
        cout << "There aren't data values to print!" << endl;
    }
}

//The Second section of the report: printing averages per sector
const void linkedList::printAveragePerSector()
{
    //if there is a list
    if (headBySector)
    {
        dataNode *current = headBySector;
        for (int sector = 1; sector <= maxSector; sector++)
        {
            if (current->data.getSector() == sector)
            {
                int sumExposure = 0;
                int sumSpeed = 0;
                int total = 0;

                //add the current sector to sums and total for integer division later
                sumExposure += current->data.getExposure();
                sumSpeed += current->data.getSpeed();
                total++;
                //we want to sum up all data that have the same sector number
                while (current->nextBySector != NULL && current->nextBySector->data.getSector() == current->data.getSector())
                {
                    current = current->nextBySector;
                    sumExposure += current->data.getExposure();
                    sumSpeed += current->data.getSpeed();
                    total++;
                }

                //finding the avg (basic math)
                int avgExposure = sumExposure / total;
                int avgSpeed = sumSpeed / total;

                //output
                cout << "Sector: #" << sector << " " << avgExposure << "% exposure, " << avgSpeed << " km/hr windspeed" << endl;

                //it's time to check the next node for the next iteration
                current = current->nextBySector;
            }
            else
            {
                cout << "Sector: #" << sector << "  -- no data -- " << endl;
            }
        }
    }
}

//displays frequency of min-max exposure
//similar to printing the averages algorithm
const void linkedList::printHistogramDataExposure()
{
    dataNode *current = headByExposure;
    int min = current->data.getExposure(); //the first exposure to start at

    for (int exposure = min; exposure <= maxExposure; exposure++)
    {
        cout << exposure << ", ";
        if (current->data.getExposure() == exposure)
        {
            int total = 1; //keeps track of how many times an exposure happens
            //loop to find all the times that a exposure happens
            while (current->nextByExposure != NULL && current->nextByExposure->data.getExposure() == current->data.getExposure())
            {
                current = current->nextByExposure;
                total++;
            }

            //output
            cout << total << endl;

            //moving onto next node
            current = current->nextByExposure;
        }
        else //means that there isn't data for the current exposure
        {
            cout << "0" << endl;
        }
    }
}

const void linkedList::printHistogramDataSpeed()
{
    dataNode *current = headBySpeed;
    int min = current->data.getSpeed(); //the first speed to start at

    for (int speed = min; speed <= maxSpeed; speed++)
    {
        cout << speed << ", ";
        if (current->data.getSpeed() == speed)
        {
            int total = 1; //keeps track of how many times an speed happens
            //loop to find all the times that a speed happens
            while (current->nextBySpeed != NULL && current->nextBySpeed->data.getSpeed() == current->data.getSpeed())
            {
                current = current->nextBySpeed;
                total++;
            }

            //output
            cout << total << endl;

            //moving onto next node
            current = current->nextBySpeed;
        }
        else //means that there isn't data for the current speed
        {
            cout << "0" << endl;
        }
    }
}

const void linkedList::printSectorList()
{
    if (headBySector)
    {
        dataNode *current = headBySector;
        //print all sectors going up until final element
        while (current->nextBySector != NULL)
        {
            cout << current->data.getSector() << ", ";
            current = current->nextBySector;
        }
        //final element printing
        cout << current->data.getSector() << endl;
    }
}

void linkedList::removeBySector(int sector)
{
    if (headBySector)
    {
        dataNode *current = headBySector;
        dataNode *next;

        // traverse the list up until there are no more possible nodes to remove
        while (current != NULL && current->data.getSector() <= sector)
        {
            /* if dataNode found with a match */
            if (current->data.getSector() == sector)
            {

                /* save current's nextBySector dataNode in the  
               pointer 'nextBySector' */
                next = current->nextBySector;

                //delete the dataNode in all three threads and deallocate memory
                modifyListForDeletionSector(current);   //modification of sector thread
                modifyListForDeletionExposure(current); //mod of exposure thread
                modifyListForDeletionSpeed(current);    //mod speed thread
                delete current;

                /* update current */
                current = next;
            }

            // go to the next node if it ain't a match
            else
                current = current->nextBySector;
        }
    }
}

void linkedList::modifyListForDeletionSector(dataNode *node)
{
    //make sure that our variables aren't null
    if (headBySector == NULL || node == NULL)
        return;

    //If node to be deleted is head node
    if (headBySector == node)
        headBySector = node->nextBySector;

    //Change nextBySector if it isn't last node
    if (node->nextBySector != NULL)
        node->nextBySector->prevBySector = node->prevBySector;
    //change max sector if we are removing the last node
    if (node->nextBySector == NULL)
        maxSector = node->prevBySector->data.getSector();

    //Change prevBySector if it isn't first node
    if (node->prevBySector != NULL)
        node->prevBySector->nextBySector = node->nextBySector;
}

void linkedList::modifyListForDeletionExposure(dataNode *node)
{
    //make sure that our variables aren't null
    if (headByExposure == NULL || node == NULL)
        return;

    //If node to be deleted is head node
    if (headByExposure == node)
        headByExposure = node->nextByExposure;

    //Change nextByExposure if it isn't last node
    if (node->nextByExposure != NULL)
        node->nextByExposure->prevByExposure = node->prevByExposure;
    //change max exposure if we are removing the last node
    if (node->nextByExposure == NULL)
        maxExposure = node->prevByExposure->data.getExposure();
    //Change prevByExposure if it isn't first node
    if (node->prevByExposure != NULL)
        node->prevByExposure->nextByExposure = node->nextByExposure;
}

void linkedList::modifyListForDeletionSpeed(dataNode *node)
{
    //make sure that our variables aren't null
    if (headBySpeed == NULL || node == NULL)
        return;

    //If node to be deleted is head node
    if (headBySpeed == node)
        headBySpeed = node->nextBySpeed;

    //Change nextBySpeed if it isn't last node
    if (node->nextBySpeed != NULL)
        node->nextBySpeed->prevBySpeed = node->prevBySpeed;
    //change max speed if we are removing the last node
    if (node->nextBySpeed == NULL)
        maxSpeed = node->prevBySpeed->data.getSpeed();

    //Change prevBySpeed if it isn't first node
    if (node->prevBySpeed != NULL)
        node->prevBySpeed->nextBySpeed = node->nextBySpeed;
}

//traverse thru list and checks to see if there is sector match (and returns true if it does),
//once it gets to a point in the list
//that the sector in the list is greater than our desired sector,
//we return false
bool linkedList::containsSector(int sector)
{
    if (headBySector)
    {
        dataNode *current = headBySector;

        //if the sector we are searching for is larger than every number in the list, don't bother searching
        if (sector > maxSector)
        {
            return false;
        }

        if (current->data.getSector() == sector)
            return true;
        if (current->data.getSector() > sector)
            return false;

        while (current->nextBySector)
        {
            current = current->nextBySector;
            if (current->data.getSector() == sector)
                return true;
            if (current->data.getSector() > sector)
                return false;
        }
    }
    else
    {
        return false;
    }
}