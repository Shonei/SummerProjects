#include "Node.hpp"
#include "LinkedList.hpp"

int main()
{
    LinkedList test;

    Node *f = new Node(1, "hello");
    Node *s = new Node(2, "there");
    Node *v = new Node(3, "!");

    test.add(f);

    test.add(s);

    test.add(v);

    test.remove(1);

    test.printList();

    std::cout << test.length() << std::endl;

    f->next->printNode();
    test.tail->prev->printNode();

    return 0;
}

