#include "Node.hpp"

template <class T1, class T2>
Node<T1, T2>::Node(const T1& d, const T2& k)
{ 
    value = d; 
    key = k; 

    next = nullptr;
    prev = nullptr;
};

template <class T1, class T2>
Node<T1, T2>::~Node()
{ 
    delete this;
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

    if(prevNode == nullptr)
    {
        nextNode->prev = nullptr;
        this = next;
    }
    else if(nextNode == nullptr)
    {
        prevNode->next = nullptr;
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
template <class T1, class T2>
void Node<T1, T2>::addBefore(Node<T1, T2> *node)
{
    if(prev == nullptr)
    {
        prev = node;
        node->next = this;
        //this = node;
    }
    else
    {
        node->prev = prev;
        prev = node;

        next->next = node;
        node->next = this;
    }
}

/*
This method will add the node passed as an argument after
the node it is called on.
*/
template <class T1, class T2>
void Node<T1, T2>::addAfter(Node<T1, T2> *node)
{
    if(next == nullptr )
    {
        node->next = nullptr;
        node->prev = this;
        next = node;
    }
    else
    {
        node->prev = prev;
        prev = node;

        next->next = node;
        node->next = this;
    }
}

template <class T1, class T2>
Node<T1, T2> Node<T1, T2>::*getNext()
{
    return next;
}

template <class T1, class T2>
Node<T1, T2> Node<T1, T2>::*getPrev()
{
    return prev;
}

template <class T1, class T2>
void Node<T1, T2>:: printNode()
{
    std::cout<< "value: " << value;
    std::cout<< " key: " << key << std::endl;
} 