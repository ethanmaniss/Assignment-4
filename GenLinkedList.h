/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* GenLinkedList interface for doubly linked list
*/
#include <iostream>

using namespace std;

template <typename E>
class GenLinkedList
{
  public:

    //destructor
    virtual ~GenLinkedList() = 0;

    // core functions
    virtual void insertFront(E data) = 0;
    virtual void insertBack(E data) = 0;
    virtual ListNode<E>* removeFront() = 0;
    virtual ListNode<E>* removeBack() = 0;
    virtual ListNode<E>* remove(E d) = 0;
    virtual ListNode<E>* peek() = 0;

    // helper functions
    virtual bool isEmpty() = 0;
    virtual void printList() = 0;
    virtual unsigned int getSize() = 0;
};
