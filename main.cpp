#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main(int argc, char** argv)
{
  LinkedQueue<int> test;
  for (int i = 0; i < 10; ++i)
  {
    test.enqueue(i);
  }
  for (int i = 0; i < 10; ++i)
  {
    cout << test.dequeue() << endl;
  }
}
