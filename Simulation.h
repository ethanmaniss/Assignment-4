#include "LinkedQueue.h"
#include "Student.h"
#include "Window.h"
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
        LinkedQueue<Student> q;


    public:
        Simulation();
        Simulation(string f);
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
    q = new LinkedQueue<Student>();
}

Simulation::Simulation(string f)
{
  fileName = f;
  currentTime = 0;
  windowsOpen = 0;
  timeStudentsArrival = 0;
  numStudentsArriving = 0;
  q = new LinkedQueue<Student>();
}

Simulation::~Simulation()
{

}

void Simulation::fileInput(string f) // string passed in will be the file name
{
    fileName = f;

    string line = "";
    ifstream file(fileName);
    if(file)
    {
        getline(file, line);
        windowsOpen = stoi(line);
        while(getline(file, line))
        {
          timeStudentsArrival = stoi(line);
          getline(file, line);
          numStudentsArriving = stoi(line);
          for (int i = 0; i < numStudentsArriving; ++i)
          {
            Student s(getline(file, line), timeStudentsArrival);
            q.enqueue(s);
          }
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
