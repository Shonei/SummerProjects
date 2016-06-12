#include "Node.hpp"

Node::Node(const int& k, const std::string& v, const int& p)
{ 
    key = k; 
    value = v; 
    possition = p;

    next = nullptr;
    prev = nullptr;
};

Node::~Node()
{ 
    // std::cout << "delte node with key: " << key << std::endl;
};

void Node:: printNode()
{
    std::cout<< "value: \"" << value << "\"";
    std::cout<< " key: " << key;
    std::cout<< " possition: " << possition << std::endl;
} 
