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
