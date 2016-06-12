#ifndef NODE_HPP
#define NODE_HPP

#include "iostream"
#include <cstddef>
#include "string"

class Node
{
    public:
        Node(const int& k = 0, 
            const std::string& v = "undeclared",
            const int& p = 0);
        ~Node();
        void printNode();
        std::string value;
        int key;  
        int possition;
        Node *next;
        Node *prev;          
};

#endif