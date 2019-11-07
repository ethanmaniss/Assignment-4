#include "LinkedQueue.h"
#include "Student.h"
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
        LinkedQueue<Student>* q;
        Window* w;
        DoublyLinkedList<Student>* s;

    public:
        Simulation();
        Simulation(string f);
        ~Simulation();

        void fileInput(string f);
        void runSimulation();
        void computeStatistics();
        bool allWindowsO(); // indicates if all windows are open
        bool allWindowsC(); // if all windows are closed



};
