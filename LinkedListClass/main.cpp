#include "Node.hpp"
#include "iostream"

int main()
{
    Node<int, char> *A = new Node<int, char>(0, 'A');

    std::cout << A->key << std::endl;
    std::cout << A->value << std::endl;

    return 0;
}

