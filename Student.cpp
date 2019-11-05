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

Student::Student(int timeNeeded, int timeWaited, int arrivalTime)
{

}
