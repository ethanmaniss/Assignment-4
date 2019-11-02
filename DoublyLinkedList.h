#include "ListNode.h"
#include <iostream>

using namespace std;

template <typename E> // allows doubly linked list to hold any kind of data
class DoublyLinkedList
{
    private:
        ListNode *front;
        ListNode *back;
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(E data);
        void insertBack(E data);
        E removeFront();
        E removeBack();
<<<<<<< HEAD
        E remove(E d); // removeAt()
        E find(int d); // contains()
=======
        E deletePos(int pos); // removeAt()
        E find(E d); // contains()
>>>>>>> da6b65bcb8f0d828b174521aa79391deb2f3b127

        bool isEmpty();
        void printList();
        unsigned int getSize();
};

template <typename E>
DoublyLinkedList::DoublyLinkedList()
{
    size = 0;
    front = NULL;
    back = NULL;
}

template <typename E>
DoublyLinkedList::~DoublyLinkedList()
{
    // research it
    // you will have to iterate through the list
    for(int i = 0; i < size; i++)
    {
        ListNode *node = front;
        front = front->next;
        delete node;
    }
}

template <typename E>
<<<<<<< HEAD
void DoublyLinkedList::insertFront(E d)
=======
void DoublyLinkedList::insertFront(E data)
>>>>>>> 79f1bea7917abf3992157b84c48bc80f0ded70f9
{
    ListNode *node = new ListNode(data);

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

template <typename E>
E DoublyLinkedList::removeFront()
{
    // check if it's empty before proceeding

    ListNode *ft = front; // temporary variable to hold the data in the front

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
    int temp = ft->data;
    delete ft;
    size--;

    return temp;
}

template <typename E>
<<<<<<< HEAD
void DoublyLinkedList::insertBack(E d)
=======
void DoublyLinkedList::insertBack(E data)
>>>>>>> 79f1bea7917abf3992157b84c48bc80f0ded70f9
{
    ListNode *node = new ListNode(data);

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

template <typename E>
E DoublyLinkedList::removeBack()
{
    // check if the list is empty

    ListNode *bk = back; // temporary variable to hold data in the back

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
    int temp = bk->data;
    delete bk;
    size--;

    return temp;
}

template <typename E>
ListNode* DoublyLinkedList::remove(E d) // aka int key
{
    // check if it's empty before attempting to remove

    ListNode *curr = front;

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

// use method from singly linked list to build insert() method

template <typename E>
bool DoublyLinkedList::isEmpty()
{
    return (front == NULL);
}
