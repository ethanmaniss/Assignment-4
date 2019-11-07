/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Student header file
*/
#include <iostream>

class Student
{
    public:
        // constructor and destructor
        Student();
        Student(int tN, int aT);
        ~Student();

        int timeNeeded;
        int timeWaited;
        int arrivalTime;
};
