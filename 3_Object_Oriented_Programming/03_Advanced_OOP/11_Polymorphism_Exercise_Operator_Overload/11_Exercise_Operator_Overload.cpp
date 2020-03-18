/*

Exercise: Operator Overload
Thus far, you've experimented with two types of polymorphism in C++.

These are runtime and compile time polymorphism. You've already seen how compile time
polymorphism is achieved with function overloading.


In this lab you'll see it can be
used for operator overloading as well. In fact, you can define any operator in the
ASCII table and give it your own set of rules!

Operator overloading can be useful for many things. Consider the + operator.
We can use it to add ints, doubles, floats, or even std::strings.

Imagine vector addition. You might want to perform vector addition on a pair of
points to add their x and y components.

The compiler won't recognize this type of
operation on its own, because this data is user defined. However, you
can overload the + operator so it performs the action that you want to implement.

=> 算子 也可以overloading


OBJECTIVES
    Create Point class.
    Define its constructor.
    Define its methods and interface.
    Declare prototype of overload method for + operator.
    Implement logic.
    Write main() function test.

*/

// include iostream for printing
#include <iostream>
class Point
{
    private:
    int x;
    int y;
    public:
    Point(int xx=0,int yy=0){
        x=xx;
        y=yy;
    }
Point operator -(Point const &obj)
{
    Point res;
    res.x=x-obj.x;
    res.y=y-obj.y;
    return res;
}
Point operator +(Point const &obj)
{
    Point res;
    res.x=x+obj.x;
    res.y=y+obj.y;
    return res;
}
void Print(){
    std::cout<<x<<std::endl;
    std::cout<<y<<std::endl;
}
};
// Test in main()
int main()
{
    Point p1(10, 5);
    Point p2(2, 4);
    Point p = p1 + p2; // An example call to "operator +"
    p1.Print();
    p2.Print();
    p.Print();

    p = p1-p2;
    p.Print();

}