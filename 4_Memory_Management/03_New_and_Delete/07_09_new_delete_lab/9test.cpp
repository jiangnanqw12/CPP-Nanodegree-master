/*
LAB 3
Objectives 3
Binary tree's are data structures that have a hierarchical form and represent trees
whose elements have a maximum number of two children. These children are called the
left and the right child. The binary tree root represents the top node.
A node that has at least one child is considered a parent of its child.
A leaf is a node that has no children.

Steps 3
    Create class called binary_tree
    Create structure called node
    Declare 4 attributes in structure: integer data, two pointers to the same type of structure,called left and right
    Declare main pointer to structure node type called root
    This pointer is attribute of class binary_tree
    This pointer is going to containt all data related to binary tree trought connectin nodes
    Declare two methods called add and search
    Add needs to have logic which will be dependant from data attribute and check for its place of
        creation on left or right side
    Search needs to be implemented as recursive function
    Check for nullptr in search and call it again on fulfilled condition(< or >)
    First function doesn't have return type
    Second function indicates its success by sending boolean values
    Both class methods are wrappers for two private class method which are going to be implemented recursively for easier usage.
    Private functions are using another input parameter -> node pointer
    This is designed like this for passage of pointers ( left, right)
    Declare two constructors and destructors
    One of the constructor - destructor pair is going to be part of node structure
    Second pair is going to be of class
    Constructors in structure is used to declare new node (Pointers are NULL, data is set)
    Constructor in class is esentially wrapper for stucture constructor
    Structure destructor deletes left and right pointers
    Class destructor deletes root pointer
    Test everything in main
*/
#include <iostream>
struct node
{
public:
    node(int initdata, node *leftN, node *rightN) : left(leftN), right(rightN), data(initdata) {}
    ~node()
    {
        if (left != nullptr)
        {
            delete left;
        }
        if (right != nullptr)
        {
            delete right;
        }
    }

    int data;
    node *left;
    node *right;
};
class binary_tree
{
private:
    node *root;
    void add(int newdata, node *ptr);
    bool search(int targetdata, node *ptr);

public:
    binary_tree(int rootdata) { root = new node(rootdata, nullptr, nullptr); }
    ~binary_tree() { delete root; }
    void addData(int inputdata) { add(inputdata, root); }
    bool searchItem(int item) { search(item, root); }
    int getroot()
    {
        return root->data;
    }
};
void binary_tree::add(int newdata, node *ptr)
{
    if (newdata > ptr->data)
    {
        if (ptr->right == nullptr)
            ptr->right = new node(newdata, nullptr, nullptr);
        else
        {
            add(newdata, ptr->right);
        }
    }
    else
    {
        if (ptr->left == nullptr)
            ptr->left = new node(newdata, nullptr, nullptr);
        else
        {
            add(newdata, ptr->left);
        }
    }
}
bool binary_tree::search(int targetdata, node *ptr)
{
    if (ptr != nullptr && ptr->right == nullptr && ptr->left == nullptr)
    {
        if (targetdata == ptr->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (targetdata == ptr->data)
        return true;
    else
    {
        if (targetdata > ptr->data && ptr->right != nullptr)
            search(targetdata, ptr->right);
        else if (targetdata < ptr->data && ptr->left != nullptr)
        {
            search(targetdata, ptr->left);
        }
    }
}
int main()
{
    binary_tree tree(2);
    tree.addData(10);
    tree.addData(1);
    tree.addData(20);
    tree.addData(0);

    std::cout << tree.searchItem(0) << std::endl;
    std::cout << tree.searchItem(9) << std::endl;
    tree.addData(11);
    std::cout << tree.searchItem(11) << std::endl;
    /* OUTPUT:
        1
        0
        1
    */

    std::cout << tree.getroot() << std::endl;
    return 0;
}