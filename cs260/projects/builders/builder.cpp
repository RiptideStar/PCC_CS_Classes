#include "builder.h"

builder::builder()
{
    id = -1;
    currentSector = -1;
}

void builder::setBuilderNum(int givenID)
{
    id = givenID;
}

void builder::addRequest(int sector, structure_type type)
{
    //create event
    event e;
    e.setBuildingType(type);
    e.setSector(sector);
    
    //add event to list
    taskList.addEvent(e);
    cout << "Builder #" << id << ": Received request to build a ";
    e.print();
}

//moving to sector
//building
bool builder::doCycle()
{
    bool listEmpty = taskList.isEmpty();
    //means the builder got some stuff to do
    if (!listEmpty)
    {
        //event containing first event to do in queue
        event e; 
        taskList.removeHead(e);

        //add the activity to the builder stack
        route.push(e); 

        //determine if the builder needs to move to a different sector to do task
        if (shouldMove(e))
        {
            cout << "Builder #" << id << ": Moving to sector " << e.getSector() << endl;
            currentSector = e.getSector();
        }

        //do the task
        cout << "Builder #" << id << ": Building a ";
        e.print();
    }
    return !listEmpty;
}

bool builder::shouldMove(event e)
{
    return currentSector != e.getSector();
}

void builder::returnHome()
{
    while (!route.isEmpty())
    {
        //event e contains popped event from stack
        event e; 
        route.pop(e);

        //determine if builder needs to move
        if (shouldMove(e))
        {
            cout << "Builder #" << id << ": Moving to sector " << e.getSector() << endl;
            currentSector = e.getSector();
        }

        //Make the connection
        cout << "Builder #" << id << ": Connected to ";
        e.print();
    }
    //Home
    cout << "Builder #" << id << ": Arrived back at base." << endl;
}