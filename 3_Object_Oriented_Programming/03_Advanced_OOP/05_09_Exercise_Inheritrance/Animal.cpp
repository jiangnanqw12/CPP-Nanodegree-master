/*

Inheritance
In this exercise you will practice building an inheritance hierarchy.

Instructions
Define a class Animal.
Define 3 member variables: color, name, age.
Define a derived class Snake that inherits from the base class Animal.
Create a member variable length for the Snake class.
Create a derived class Cat that inherits from the base class Animal.
Create a member variable height for the Cat class.
Create MakeSound() member functions for each of the derived classes.
In the main() function instantiate Snake and Cat objects. Initialize both their unique and derived attributes.
Program them to make a sound.

*/

#include <iostream>
#include <string>

// Define base class Animal

class Animal{


public:

    Animal(std::string c, std::string n, int a): color(c), name(n), age(a){}


    std::string color="none";
    std::string name="none";
//private://如果宣告成 private, 子class 中也不能用, 也就是get_info 會報錯
protected: // 子class 內部可以使用
    int age=0;

};

// Declare derived class Snake
class Snake:public Animal{
    float length;
    
}
// Declare derived class Cat



// Test in main()

int main (){


    Snake mys(100);
    mys.get_info();
    Cat myc(50);
    myc.get_info();


}
