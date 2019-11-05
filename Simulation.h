#include "ListNode.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include <string> // for string class
#include <fstream> // for file input/output

#include <iostream>

using namespace std;

class Simulation
{
    private:
        int currentTime;
        int windowsOpen;
        int timeStudentsArrival;
        int numStudentsArriving;
        string fileName;


    public:
        Simulation();
        ~Simulation();

        void runSimulation();
        void computeStatistics(Simulation s);



};

Simulation::Simulation()
{
    currentTime = 0;
    windowsOpen = 0;
    timeStudentsArrival = 0;
    numStudentsArriving = 0;
    fileName = "";
}

Simulation::~Simulation()
{

}

void Simulation::fileInput(string f) // string passed in will be the file name
{
    fileName = f;

    int number;
    ifstream file(fileName);
    if(file.is_open())
    {
        getline(file,number);
        windowsOpen = number;
        getline(file,number);
        timeStudentsArrival = number;

        while(getline(file,number))
        {
            
        }


        file.close();
    }
    else
    {
        cout << "File cannot be opened." << endl;
    }

}

void Simulation::runSimulation()
{

}

void Simulation::computeStatistics(Simulation s)
{

}
