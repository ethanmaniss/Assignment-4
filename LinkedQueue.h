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
        E& front();
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

template <typename E>
int LinkedQueue<E>::size()
{
    return n;
}

template <typename E>
bool LinkedQueue<E>::isEmpty()
{
    return(n == 0);
}

template <typename E>
E& LinkedQueue<E>::front()
{
    if(isEmpty())
    {
        cout << "Front of an empty queue." << endl;
    }
    return L.removeFront();
}

template <typename E>
void LinkedQueue<E>::enqueue(E e)
{
    L.insertFront(e);
    n++;
}

template <typename E>
E LinkedQueue<E>::dequeue()
{
    if(isEmpty())
    {
        cout << "Dequeue of an empty queue." << endl;
    }
    n--;
    return L.removeFront();
}
