#include <iostream>

class Student
{
    public:
        Student();
        Student(int tN, int aT);
        ~Student();
        
        int timeNeeded;
        int timeWaited;
        int arrivalTime;
};
