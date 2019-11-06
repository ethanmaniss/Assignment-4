#include <iostream>
#include "Student.h"

class Window
{
    public:
        Window();
        ~Window();
        Student* currS;

        int idleTime;
        bool idleFiveMin; // idle for longer than 5 minutes
};
