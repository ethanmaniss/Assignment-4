/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* Window implementation file
*/
#include "Window.h"
#include <iostream>

using namespace std;

Window::Window() // default constructor
{
    idleTime = 0;
    currS = NULL;
}

Window::~Window() // destructor
{
  delete currS;
}
