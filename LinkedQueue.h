/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* LinkedQueue template class
*/
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template <typename E> // allows queue to store any kind of object
class LinkedQueue
{
    public:
        LinkedQueue();
        ~LinkedQueue();

        int size();
        bool isEmpty();
        E front();
        void enqueue(E e);
        E dequeue();

    private:
        DoublyLinkedList<E> L; // double linked list version of a queue
        int n; // number of elements in list
};

template <typename E>
LinkedQueue<E>::LinkedQueue() // default constructor
{
    L = DoublyLinkedList<E>();
    n = 0;
}

template <typename E>
LinkedQueue<E>::~LinkedQueue() // destructor
{

}

// returns size
template <typename E>
int LinkedQueue<E>::size()
{
    return n;
}

// returns true if empty
template <typename E>
bool LinkedQueue<E>::isEmpty()
{
    return(n == 0);
}

// returns data in front of queue but does not remove
template <typename E>
E LinkedQueue<E>::front()
{
    if(!isEmpty())
    {
        return L.peek()->data;
    }
    else
    {
        cout << "Front of an empty queue." << endl;
    }
}

// adds node to back of linked list/queue
template <typename E>
void LinkedQueue<E>::enqueue(E e)
{
    L.insertBack(e);
    n++;
}

// removes node from front of linked list/queue
template <typename E>
E LinkedQueue<E>::dequeue()
{
    if(!isEmpty())
    {
        n--;
        return L.removeFront()->data;
    }
    else
    {
        cout << "Dequeue of an empty queue." << endl;
    }
}
