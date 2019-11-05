#include <iostream>

class Window
{
    private:
        int idleTime;
        bool idleFiveMin; // has been idle for longer than 5 minutes

    public:
        Window();
        ~Window();
};
