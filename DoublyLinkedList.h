/*
* Ethan Dang, Ethan Mannis
* CPSC 350-01/02
* Assignment 4
* DoublyLinkedList template class
*/
#include "ListNode.h"
#include "GenLinkedList.h"
#include <iostream>

using namespace std;

template <typename E> // allows doubly linked list to hold any kind of data
class DoublyLinkedList : public GenLinkedList<E>
{
    private:
        ListNode<E> *front;
        ListNode<E> *back;
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(E data);
        void insertBack(E data);
        ListNode<E>* removeFront();
        ListNode<E>* removeBack();
        ListNode<E>* remove(E d); // remove node containing d
        ListNode<E>* peek();

        // helper functions
        bool isEmpty();
        void printList();
        unsigned int getSize();
};

// default constructor
template <typename E>
DoublyLinkedList<E>::DoublyLinkedList()
{
    size = 0;
    front = NULL;
    back = NULL;
}

// destructor
template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList()
{
    for(int i = 0; i < size; i++)
    {
        ListNode<E> *node = front;
        front = front->next;
        delete node;
    }
}

// virtual destructor
template <typename E>
GenLinkedList<E>::~GenLinkedList()
{

}

// inserts new node with data d to front
template <typename E>
void DoublyLinkedList<E>::insertFront(E d)
{
    ListNode<E> *node = new ListNode<E>(d);

    if(isEmpty())
    {
        // we have an empty list
        back = node;
    }
    else
    {
        // not an empty list
        front->prev = node;
        node->next = front;
    }
    front = node;
    size++;

}

// removes and returns node in front
template <typename E>
ListNode<E>* DoublyLinkedList<E>::removeFront()
{
    // check if it's empty before proceeding

    ListNode<E> *ft = front; // temporary variable to hold the data in the front

    if(front->next == NULL) // size == 1 or front = back
    {
        // only one node in the list
        back = NULL;
    }
    else
    {
        // list has more than one node
        front->next->prev = NULL;
    }
    front = front->next;
    ft->next = NULL;
    size--;

    return ft;
}

// inserts node with data d and inserts to back
template <typename E>
void DoublyLinkedList<E>::insertBack(E d)
{
    ListNode<E> *node = new ListNode<E>(d);
    if(isEmpty()) // size == 0
    {
        // we have an empty list
        front = node;
    }
    else
    {
        // not an empty list
        back->next = node;
        node->prev = back;
    }
    back = node;
    size++;
}

// removes and returns node at back of list
template <typename E>
ListNode<E>* DoublyLinkedList<E>::removeBack()
{
    // check if the list is empty

    ListNode<E> *bk = back; // temporary variable to hold data in the back

    if(back->prev == NULL) // size == 1 or front = back
    {
        front = NULL; // only one node in the list
    }
    else
    {
        // list has more than one node
        back->prev->next == NULL;
    }
    back = back->prev;
    bk->prev = NULL;
    size--;

    return bk;
}

// removes node containing data d
template <typename E>
ListNode<E>* DoublyLinkedList<E>::remove(E d) // aka int key
{
    // check if it's empty before attempting to remove

    ListNode<E> *curr = front;

    while(curr->data != d)
    {
        // let's look for the key/value to be removed

        curr = curr->next;

        if(curr == NULL) // value we are looking for does not exist in the list
        {
            return NULL;
        }
    }

    // we found the node/value to be removed
    if(curr == front)
    {
        // node to be removed is the front
        front = curr->next;
    }
    else
    {
        // it's not the front
        curr->prev->next = curr->next;
    }

    if(curr == back)
    {
        back = curr->prev;
    }
    else
    {
        // not the back
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;

    size--;

    return curr;
}

// indicates if list is empty
template <typename E>
bool DoublyLinkedList<E>::isEmpty()
{
    return (front == NULL);
}

// returns front of list but does not remove
template <typename E>
ListNode<E>* DoublyLinkedList<E>::peek()
{
    if(!isEmpty())
    {
        return front;
    }
    else
    {
        cout << "Linked List is empty." << endl;
        return NULL;
    }
}

// returns size of list
template<typename E>
unsigned int DoublyLinkedList<E>::getSize()
{
  return size;
}

// prints every value in list
template <typename E>
void DoublyLinkedList<E>::printList()
{
  ListNode<E>* current = front;
  while (current != NULL)
  {
    cout << current->data << endl;
    current = current->next;
  }
}
