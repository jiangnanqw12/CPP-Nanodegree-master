/*
Doubly linked lists
Doubly linked list is a type of data structure that is made up of so called objects
that are created using self referential structures. Each of these nodes contain three
attributes, namely the value and the reference to the next list object and the reference
to the previous list object.

Because the list is linked in both directions, any node has the ability to access any
other node. That means that the user of a doubly linked list need only keep track of
a single node.

The last node in the list points forward to nothing, which can be represented by nullptr.
The same is true for the first node in the list, which points backward to nothing.

In this exercise you will create a doubly linked list, which exposes 4 methods:

    push_back(): add values to the end of the list
    push_front(): add values to the beginning to the list
    pop_back(): delete values from the end of the list
    pop_front(): delete values from the front of the list

Also, you will implement a helper function, empty(), which returns whether or not
the list has any nodes.

Steps
    Declare class List to represent the doubly linked list
    Declare struct Node to represent the nodes in the list
    Declare a constructor for struct Node
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a constructor for the doubly linked list
    Declare a destructor for class List
    Implement the class List destructor to delete all of the nodes in the list
    Declare List::PushFront() to push nodes onto the front of the list
    Declare List::PushBack() to push nodes onto the back of the list
    Declare List::PopFront() to delete nodes from the front of the list
    Declare List::PopBack() to delete nodes from the back of the list
    Declare List::Size() to count the number of nodes in the list
    Test that all member functions in class List behave properly, even if the list is empty

*/

#include <iostream>
#include <assert.h>
#include <string>

template <class T>
class Node
{
public:
    Node(T _value, Node *_previous_node, Node *_next_node) : value(_value), previous_node(_previous_node), next_node(_next_node) {}

    T value;

    Node *previous_node;
    Node *next_node;
};
template <class T>
class List
{
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List();

    Node<T> *head;
    Node<T> *tail;

    void PushFront(T val);
    void PushBack(T val);
    T PopFront();
    T PopBack();
    int Size() const;
    bool Empty() const;
};

template <class T>
List<T>::~List()
{
    while (List<T>::head != nullptr)
    {
        Node<T> *tmp = head;
        head = head->next_node;
        delete tmp;
    }
}

template <class T>
void List<T>::PushBack(T val)
{

    List<T>::tail = new Node<T>(val, List<T>::tail, nullptr);
    if (head == nullptr)
    {
        head = tail;
    }
    else
    {
        List<T>::tail->previous_node->next_node = tail;
    }
}
template <class T>
void List<T>::PushFront(T val)
{

    List<T>::head = new Node<T>(val, nullptr, List<T>::head);
    if (tail == nullptr)
    {
        tail = head;
    }
    else
    {
        head->next_node->previous_node = head;
    }
}

// template <class T>
// int List<T>::Size() const
// {
//     int count = 0;
//     Node<T> *tmp = head; // copy head to tmp
//     //Node<T> *tmp(List<T>::head);
//     //std::cout << "tmp addr:" << &tmp <<", head addr: "<< &head << std::endl;
//     std::string rst = "";
//     while (tmp != nullptr)
//     {
//         rst = rst + std::to_string(tmp->value) + ", ";
//         tmp = tmp->next_node;
//         count++;
//     }
//     //std::cout << "End tmp val:" << tmp <<", head val: "<<head << std::endl;
//     std::cout << rst << std::endl;
//     return count;
// }

template <class T>
int List<T>::Size() const
{
    Node<T> *tmp = head;
    int counter = 0;
    while (tmp != nullptr)
    {
        tmp = tmp->next_node;
        counter++;
    }
    return counter;
}

template <class T>
T List<T>::PopFront()
{
    if (Empty())
    {
        throw("errors");
    }

    Node<T> *tmp = head;
    head = head->next_node;
    T value = tmp->value;
    if (head == nullptr)
    {
        tail == nullptr;
    }
    else
    {
        head->previous_node = nullptr;
    }

    delete tmp;
    return value;
}
template <class T>
T List<T>::PopBack()
{
    Node<T> *tmp = tail;
    tail = tail->previous_node;
    T value = tmp->value;
    if (tail == nullptr)
    {
        head == nullptr;
    }
    else
    {
        tail->next_node = nullptr;
    }
    delete tmp;
    return value;
}

template <class T>
bool List<T>::Empty() const { return (head == nullptr); }
int main()
{
    // Sanity test
    List<int> list1;

    list1.PushBack(9);
    std::cout << "Size() = " << list1.Size() << std::endl;
    assert(list1.Size() == 1);

    // Deeper test
    List<int> list2;
    list2.PushFront(9);
    std::cout << "1" << std::endl;
    list2.PushBack(10);
    std::cout << "2" << std::endl;
    assert(list2.Size() == 2);
    std::cout << "3" << std::endl;

    list2.PushBack(15);
    std::cout << "4" << std::endl;
    list2.PushFront(2);
    std::cout << "5" << std::endl;
    std::cout << "Size() = " << list2.Size() << std::endl;

    assert(list2.PopFront() == 2);
    std::cout << "list2.PopFront() = " << list2.PopFront() << std::endl;
    std::cout << "Size() = " << list2.Size() << std::endl;

    assert(list2.PopBack() == 15);
    assert(list2.Size() == 1);
}