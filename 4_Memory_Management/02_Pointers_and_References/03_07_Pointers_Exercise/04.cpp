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
class List
{
    class Node
    {
        Node();
    };
    Node *ptr2head;
    List();
    void destructor();
    void PushFront();
    void PushBack();
    void PopFront();
    void PopBack();
    void Size();
    bool empty();
};
void List::destructor()
{
}
void List::PushFront()
{
}
void List::PushBack()
{
}
void List::PopFront()
{
}
void List::PopBack()
{
}
void List::Size()
{
}
bool List::empty()
{
}