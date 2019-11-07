/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Simulation implementation file
*/
#include "Simulation.h"
#include <string> // for string class
#include <fstream> // for file input/output
#include <algorithm> // for sort() function in computeStatistics() method

#include <iostream>

using namespace std;

// default constructor
Simulation::Simulation()
{
    currentTime = 0;
    windowsOpen = 0;
    timeStudentsArrival = 0;
    numStudentsArriving = 0;
    fileName = "";
    q = new LinkedQueue<Student*>();
    s = new DoublyLinkedList<Student*>();
}

// overloaded constructor
Simulation::Simulation(string f)
{
  fileName = f;
  currentTime = 0;
  windowsOpen = 0;
  timeStudentsArrival = 0;
  numStudentsArriving = 0;
  q = new LinkedQueue<Student*>();
}

// destructor
Simulation::~Simulation()
{
  delete q;
  delete s;
  delete []w;
}

// takes info from text file, creates student and adds to queue
void Simulation::fileInput()
{
    string line = "";
    ifstream file(fileName); // opens stream of data from file to program
    if(file)
    {
        getline(file, line);
        windowsOpen = stoi(line); // gets number of windows open and converts string to int
        w = new Window[windowsOpen]; // creates array of windows, will be size of windowsOpen
        for (int i = 0; i < windowsOpen; ++i)
        {
          w[i] = *new Window();
        }
        while(getline(file, line))
        {
          timeStudentsArrival = stoi(line);
          getline(file, line);
          numStudentsArriving = stoi(line);
          for (int i = 0; i < numStudentsArriving; ++i)
          {
            getline(file, line);
            Student* s = new Student(stoi(line), timeStudentsArrival);
            q->enqueue(s); // adds students to the queue from the back
          }
        }
        file.close(); // closes stream of data
    }
    else
    {
        cout << "File cannot be opened." << endl;
    }

}

// runs Simulation and calcs wait times and idle times
void Simulation::runSimulation()
{
    currentTime = 0;
    while(!q->isEmpty() || !allWindowsO()) // while queue is not empty and all windows are not open
    {
      if (currentTime == 0) // special case to avoid added extra idle time to windows
      {
        while (!q->isEmpty() && q->front()->arrivalTime == currentTime && !allWindowsC()) // while there are students arriving at time 0 and there are still open windows
        {
          for (int i = 0; i < windowsOpen; ++i)
          {
            if (w[i].currS == NULL) // window open
              w[i].currS = q->dequeue();
          }
        }
      }
      else
      {
        for (int i = 0; i < windowsOpen; ++i)
        {
          if (w[i].currS == NULL) // no student at window
          {
            ++w[i].idleTime;
          }
          else // student at window
          {
            w[i].currS->timeNeeded--;
            if (w[i].currS->timeNeeded == 0) // student finished at window
            {
              Student* temp = w[i].currS;
              s->insertBack(temp); // adds student to finished student list
              w[i].currS = NULL;
            }
          }
        }
        while (!q->isEmpty() && q->front()->arrivalTime <= currentTime && !allWindowsC()) // while student is in queue and there is an open window
        {
          for (int i = 0; i < windowsOpen; ++i)
          {
            if (w[i].currS == NULL && !q->isEmpty()) // window open
            {
              w[i].currS = q->dequeue();
              w[i].currS->timeWaited = currentTime - w[i].currS->arrivalTime; // sets time waited in queue to current time - time of arrival
            }
          }
        }
      }
      currentTime++;
    }
}

// calculates statistics after simulation has been run
void Simulation::computeStatistics()
{
    double avgWait; // variable for average student wait time
    int numStudents = s->getSize();
    int sWait[numStudents];
    int waitTenMin = 0; // number of students waiting over ten minutes
    int i = 0;
    while (!s->isEmpty())
    {
      sWait[i] = s->removeFront()->data->timeWaited;
      if (sWait[i] >= 10)
        ++waitTenMin;
      avgWait += sWait[i];
      ++i;
    }
    avgWait = avgWait/numStudents; // divides total by size to get avg


    double avgIdle; // variable for average window idle time
    int wIdle[windowsOpen]; // array of window idle time integers
    int longestIdle; // longest window idle time
    int max = 0; // max value in window array
    int idleFiveMin = 0; // number of windows idle over five minutes
    for(int j = 0; j < windowsOpen; ++j)
    {
        avgIdle += w[j].idleTime;
        wIdle[j] = w[j].idleTime; // creates new array of idle time integers
        if(wIdle[j] > max)
        {
            longestIdle = max;
        }
        if(w[j].idleTime >= 5)
        {
            idleFiveMin++;
        }
    }
    avgIdle = avgIdle/windowsOpen; // divides total by size to get avg

    int medianWait; // median student wait time
    sort(sWait, sWait + numStudents); // vars s and sWait have the same size
    int mid = numStudents/2; // middle number of array of wait time integers
    if(numStudents % 2) // if size is even
    {
        medianWait = (sWait[mid] + sWait[mid+1])/2;
    }
    else // if size is odd
    {
        medianWait = sWait[mid]; // just accesses middle number
    }
    int longestWait = sWait[numStudents-1]; // longest student wait time

    cout << "sim and stats done" << endl;

    cout << "Mean student wait time: " << avgWait << endl;
    cout << "Median student wait time: " << medianWait << endl;
    cout << "Longest student wait time: " << longestWait << endl;
    cout << "Number of students waiting over 10 min: " << waitTenMin << endl;
    cout << "Mean window idle time: " << avgIdle << endl;
    cout << "Longest window idle time: " << longestIdle << endl;
    cout << "Number of windows idle for over 5 min: " << idleFiveMin << endl;
}

bool Simulation::allWindowsO() // returns true if all windows are open
{
  for (int i = 0; i < windowsOpen; ++i)
  {
    if (w[i].currS != NULL) // someone at window
      return false;
  }
  return true;
}

bool Simulation::allWindowsC() // returns true if all windows are closed
{
  for (int i = 0; i < windowsOpen; ++i)
  {
    if (w[i].currS == NULL) // someone at window
      return false;
  }
  return true;
}
