/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Simulation header file
*/
#include "LinkedQueue.h"
#include "Window.h"
#include <string> // for string class

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
        LinkedQueue<Student*>* q;
        Window* w;
        DoublyLinkedList<Student*>* s;

    public:
        // constructor and destructor
        Simulation();
        Simulation(string f);
        ~Simulation();

        void fileInput(); // gets simulation parameters for statistics
        void runSimulation();
        void computeStatistics();
        bool allWindowsO(); // indicates if all windows are open
        bool allWindowsC(); // if all windows are closed



};
