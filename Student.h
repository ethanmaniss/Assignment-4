#include <iostream>

class Student
{
    private:
        int timeNeeded;
        int timeWaited;
        int arrivalTime;

    public:
        Student();
        Student(int tN, int aT);
        ~Student();
};
