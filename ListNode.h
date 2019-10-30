#include <iostream>

using namespace std;

template <typename E> // allows node to hold any kind of data
class ListNode
{
    public:
        ListNode *next;
        ListNode *prev;
        E data;

        //constructor/destructor
        ListNode();
        ListNode(E d);
        ~ListNode();
};

template <typename E>
ListNode::ListNode()
{

}

template <typename E>
ListNode::~ListNode()
{
    next = NULL;
    prev = NULL;
}

template <typename E>
ListNode::ListNode(E d)
{
    data = d;
    next = NULL; // nullptr
    prev = NULL;
}
