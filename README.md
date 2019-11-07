# Assignment-4
Registrar's Office Simulation

Ethan Dang
2326380
edang@chapman.edu
CPSC 350-02
Assignment 4

Ethan Maniss
2324967
maniss@chapman.edu
CPSC 350-03
Assignment 4

"DoublyLinkedList.h"
"GenLinkedList.h"
"LinkedQueue.h"
"ListNode.h"
"main.cpp"
"Simulation.cpp"
"Simulation.h"
"Student.cpp"
"Student.h"
"Window.cpp"
"Window.h"

Book was used for help in creating doubly-linked list based queue.

https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
Reference was used to figure out the sort() function

Our program successfully compiles but there is a runtime error.
There was an unknown "segmentation fault" error in our program.
We figured out the error is produced during the insertBack() method for the doubly
linked list. In addition to this, we do not know why both the if() and following else() statements
are both executed in our main method, which seems to go against the fundamentals of if statements.

g++ *.cpp
./a.out (yourfilename.txt)
