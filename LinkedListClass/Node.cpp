#include "Node.hpp"

template <class T1, class T2>
Node<T1, T2>::Node(const T1& d, const T2& k)
{ 
    value = d; 
    key = k; 

    next = NULL;
    prev = NULL;
};

template <class T1, class T2>
void Node<T1, T2>::changeValue(const T1& d)
{
    value = d;
}

template <class T1, class T2>
T1 Node<T1, T2>::getValue()
{
    return value;
}

template <class T1, class T2>
T2 Node<T1, T2>::getKey()
{
    return key;
}

template <class T1, class T2>
void Node<T1, T2>::remove()
{
    Node<T1, T2> *prevNode = prev;
    Node<T1, T2> *nextNode = next;

    if(prevNode == NULL)
    {
        nextNode->prev = NULL;
        this = next;
    }
    else if(nextNode == NULL)
    {
        prevNode->next = NULL;
    }
    else
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    delete this;
}
/*
This method adds the node that is being passed as an argument 
before the node that is being called on.
*/
void Node<T1, T2>::addBefore(Node<T1, T2>)
{
    
}
