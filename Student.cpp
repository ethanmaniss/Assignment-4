/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Student implementation file
*/
#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() // student default constructor
{
    timeNeeded = 0;
    timeWaited = 0;
    arrivalTime = 0;
}

Student::~Student() // student destructor
{

}

Student::Student(int tN, int aT) // overloaded constructor
{
  timeNeeded = tN;
  timeWaited = 0;
  arrivalTime = aT;
}
