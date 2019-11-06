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
        Window* w;
        DoublyLinkedList<Student> s;

    public:
        Simulation();
        Simulation(string f);
        ~Simulation();

        void runSimulation();
        void computeStatistics(Simulation s);
        bool allWindowsO(); // indicates if all windows are open
        bool allWindowsC(); // if all windows are closed



};

Simulation::Simulation()
{
    currentTime = 0;
    windowsOpen = 0;
    timeStudentsArrival = 0;
    numStudentsArriving = 0;
    fileName = "";
    q = new LinkedQueue<Student>();
    s = new DoublyLinkedList<Student>();
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
        w = new Window[windowsOpen];
        while(getline(file, line))
        {
          timeStudentsArrival = stoi(line);
          getline(file, line);
          numStudentsArriving = stoi(line);
          for (int i = 0; i < numStudentsArriving; ++i)
          {
            Student s = new Student(getline(file, line), timeStudentsArrival);
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
    currentTime = 0;
    cout << currentTime << endl;
    cout << windowsOpen << endl;
    cout << timeStudentsArrival << endl;
    cout << numStudentsArriving << endl;
    while(!q.isEmpty() || !allWindowsO()) // while queue is not empty and all windows are not open
    {
      if (currentTime == 0) // special case to avoid added extra idle time to windows
      {
        while (q.front()->arrivalTime == currentTime && !allWindowsC()) // while there are students arriving at time 0 and there are still open windows
        {
          for (int i = 0; i < windowsOpen; ++i)
          {
            if (w[i]->currS == NULL) // window open
              w[i]->currS = q.dequeue();
          }
        }
      }
      else
      {
        for (int i = 0; i < windowsOpen; ++i)
        {
          if (w[i]->currS == NULL) // no student at window
          {
            ++w[i]->idleTime;
            if (w]i]->idleTime == 5)
              w[i]->idleFiveMin = true;
          }
          else // student at window
          {
            w[i]->currS->timeNeeded--;
            if (w[i]->currS->timeNeeded == 0) // student finished at window
            {
              s.insertBack(w[i]->currS); // adds student to finished student list
              w[i]->currS = NULL;
            }
          }
        }
        while (q.front()->arrivalTime <= currentTime && !allWindowsC()) // while student is in queue and there is an open window
        {
          for (int i = 0; i < windowsOpen; ++i)
          {
            if (w[i]->currS == NULL) // window open
            {
              w[i]->currS = q.dequeue();
              w[i]->currS->timeWaited = currentTime - w[i]->currS->arrivalTime; // sets time waited in queue to current time - time of arrival
            }
          }
        }
      }
      currentTime++;
    }
}

void Simulation::computeStatistics(Simulation s)
{

}

bool Simulation::allWindowsO() // returns true if all windows are open
{
  for (int i = 0; i < windowsOpen; ++i)
  {
    if (w[i]->currS != NULL) // someone at window
      return false;
  }
  return true;
}

bool Simulation::allWindowsC() // returns true if all windows are closed
{
  for (int i = 0; i < windowsOpen; ++i)
  {
    if (w[i]->currS == NULL) // someone at window
      return false;
  }
  return true;
}
