#include <iostream>

using namespace std;

template <typename E> // allows node to hold any kind of data
class ListNode
{
    public:
        ListNode<E> *next;
        ListNode<E> *prev;
        E data; // E can be any element of data

        //constructor/destructor
        ListNode();
        ListNode(E d);
        ~ListNode();
};

template <typename E>
ListNode<E>::ListNode() // default constructor
{
  next = NULL;
  prev = NULL;
  data = NULL;
}

template <typename E>
ListNode<E>::~ListNode() // destructor
{
    next = NULL;
    prev = NULL;
}

template <typename E>
ListNode<E>::ListNode(E d) // overloaded constructor
{
    data = d;
    next = NULL; // nullptr
    prev = NULL;
}
