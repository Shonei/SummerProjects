#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"
#include <cstddef>

class LinkedList
{
    public:
        Node *head;
        Node *tail;
        LinkedList();
        ~LinkedList();
        void clear();
        void add(Node *newNode, const int& t = 0);
        void remove(const int& t);  
        void printList();
        void printInReverse();
        bool isEmpty();
        int length();
};

#endif