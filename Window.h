/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Window header file
*/
#include "Student.h"
#include <iostream>

class Window
{
    public:
        // constructor and destructor
        Window();
        ~Window();

        // student at window
        Student* currS;
        
        int idleTime;
};
