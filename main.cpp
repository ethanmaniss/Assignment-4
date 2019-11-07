/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Main class, runs methods for simulation object
*/
#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 2)
  {
    Simulation s(argv[1]);
    s.fileInput();
    s.runSimulation();
    s.computeStatistics();
  }
  else
  {
    cout << "Error: improper format, try again" << endl;
  }
}
