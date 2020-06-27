/*
LAB 2
Objectives 2
In this example we are showing technique of an implementation of function which
will return multiple values. Using pointers we can implement this via references.
If we take into consideration that passage of data by reference doesn't copy this object,
we can pass our object to a function and execute required actions. In this example we are
going to make a primitive function which calculates cosine and sine values of a specific
angle (in radians) using just one function.

Steps 2
    Include standard library iostream
    Include math.h library for usage of trigonometrical functions
    create a function which will have three parameters: _sin, _cos and angle. all
        parameters are double
    Return type of this function is void
    Declare input parameters (except angle variable) as pointers to double type
    Create main function
    Declare three double variables: angle, _sin, _cos
    Ask for input value of angle via cin from a user
    Call trigonometry function (pass sin and cos variables by references)
    Print results in console
*/

#include <iostream>
#include <cmath>
void trigonometry(double *_sin, double *_cos, double angle);
int main()
{
    double angle;
    double _sin;
    double _cos;
    std::cin >> angle;
    trigonometry(&_sin, &_cos, angle);
    std::cout << _sin << std::endl;
    std::cout << _cos << std::endl;
}
void trigonometry(double *_sin, double *_cos, double angle)
{
    *_sin = std::sin(angle);
    *_cos = std::cos(angle);
}
