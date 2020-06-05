/*
Pointer Project LAB
Description
Using pointers we are going to create first part of our project.
In this lab using knowledge from pointers and references we are going to create our
generic class called "PtrDetails". This class defines an element that is stored in the
garbage collection information list.

Steps
    Declare generic class PtrDetails
    Create generics via templates
    all attributes and methods are going to be public, because they are going to be used by other classes
    create attribute for refcount
    create attribute memPtr as generic pointer for storage of basic info about memory
    create bool attribute isArray for recognition of memory type allocated
    create attribute arraySize for working with array allocation
    Declare constructor for PtrDetails which will have two parameters
    First constructor paremeter is going to be pointer and second which is not required,
        is going to be size of eventual array in memory
    We need to construct logic of the constructor which will set isArray attribute if size is larger then 0
    Create overload operator == which will be used for comparison between to PtrDetails
        object in lists. It is mandatory

*/
template <class T>
class PtrDetails
{
public:
    int refcount;
    T *memPtr;
    bool isArray;
    int arraySize;
    PtrDetails(T *Ptr, int Size) : memPtr(Ptr), arraySize(Size)
    {
        if (arraySize > 0)
        {
            isArray = true;
        }
        else
        {
            isArray = false;
        }
    };
};
// void test()
// {
//     PtrDetails<int> t();
// }
template <class T>
bool operator==(const PtrDetails<T> &obj1, const PtrDetails<T> &obj2)
{
    if (obj1->memPtr == obj2->memPtr)
    {
        return true;
    }
    else
    {
        return false;
    }
}