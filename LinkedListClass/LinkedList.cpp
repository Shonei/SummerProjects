#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = new Node(0, "undef", -1);
    tail = new Node(0, "undef", -1);
    head->next = tail;
    tail->prev = head;
}

LinkedList::~LinkedList()
{
    while(head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::isEmpty()
{
    if(head->next == nullptr)
    {
        return true;
    }

    return false;
}

void LinkedList::add(Node *newNode, const int& t)
{
    if(t > length() || t < 0)
    {
        throw std::out_of_range("You can't add a node at that possition.");
    }
    
    Node *temp = head;

    // if(temp->next == nullptr)
    // {
    //     temp->next = newNode;
    //     newNode->prev = temp;
    // }
    // else 
    // {
        for( ; temp->next != nullptr; temp = temp->next)
        {
            if(temp->possition == t )
            {
                break;
            }
        }

        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev = newNode;
    // }

    temp = head->next;
    for( ; temp->next != nullptr; temp = temp->next )
    {
        temp->possition = temp->prev->possition + 1;
    }
}

void LinkedList::printList()
{
    Node *temp = head->next;
    for(; temp->next != nullptr; temp = temp->next)
    {
        temp->printNode();
    }
}

void LinkedList::printInReverse()
{
    Node *temp = tail->prev;
    for(; temp->prev != nullptr; temp = temp->prev)
    {
        temp->printNode();
    }   
}

int LinkedList::length()
{
    Node *temp = head->next;
    int r = 0;
    for( ; temp->next != nullptr; temp = temp->next )
    {
        r++;
    }

    return r;
}

void LinkedList::remove(const int& t)
{
    if(t > length() || t < 0)
    {
        throw std::out_of_range("There is no node in that possitipn.");
    }

    Node *temp = head;
    for( ; temp->next != nullptr; temp = temp->next)
    {
        if(temp->possition == t )
        {   
            break;
        }
    }

    // if(temp->next != nullptr)
    // {
    //     temp->prev->next = nullptr;
    //     delete temp;
    // }
    // else
    // {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp; 
    // }

    Node *ttemp = head->next;
    for( ; ttemp->next != nullptr; ttemp = ttemp->next )
    {
        ttemp->possition = ttemp->prev->possition + 1;
    }
}