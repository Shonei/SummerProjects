#include "Node.hpp"
#include "Node.cpp"

int main()
{
    Node<int, int> *first = new Node<int, int>(1, 2);
    Node<int, int> *second = new Node<int, int>(13, 23);
    Node<int, int> *third = new Node<int, int>(1235, 234);
    Node<int, int> *forth = new Node<int, int>(123, 4544);
    // first->printNode();
    // first->changeValue(30);

    first->addBefore(second);
    first->getPrev()->printNode();
    
    return 0;
    /*
    this method might have to be removed
    first->remove();
    */
}

