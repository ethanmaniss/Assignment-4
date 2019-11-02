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
        E& front()
        void enqueue(E& e);
        void dequeue();

    private:
        DoublyLinkedList L; // double linked list version of a queue
        int n; // number of elements in list
};

template <typename E>
LinkedQueue::LinkedQueue() // default constructor
{
    DoublyLinkedList L = DoublyLinkedList();
    n = 0;
}

template <typename E>
LinkedQueue::~LinkedQueue() // destructor
{

}

template <typename E>
int LinkedQueue::size()
{
    return n;
}

template <typename E>
bool LinkedQueue::isEmpty()
{
    return(n == 0);
}

template <typename E>
E& LinkedQueue::front()
{
    if(isEmpty())
    {
        cout << "Front of an empty queue." << endl;
    }
    return L.removeFront();
}

template <typename E>
void LinkedQueue::enqueue(E& e)
{
    L.insertFront(e);
    n++;
}

template <typename E>
void LinkedQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "Dequeue of an empty queue." << endl;
    }
    L.removeFront();
    n--;
}
