#include <iostream>

using namespace std;

class GenLinkedList
{
  public:

    //destructor
    virtual ~GenLinkedList() = 0;

    virtual bool isEmpty() = 0;
    virtual void printList() = 0;
    virtual unsigned int getSize() = 0;
};
