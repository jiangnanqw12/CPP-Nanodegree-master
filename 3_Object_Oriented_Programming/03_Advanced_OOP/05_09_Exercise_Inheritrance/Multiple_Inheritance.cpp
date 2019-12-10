#include <iostream>
#include <string>
#include <assert.h>

class Animal {
public:
    double age;
};

class Pet {
public:
    std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
    std::string breed;
};


class Cat:public Animal,public Pet{
    public:
    std::string color;
    int age;
    std::string name;
    Cat(std::string n,int a,std::string c):color(c),age(a),name(n){}
    void get_info()
    {
        std::cout<<color<<std::endl;
        std::cout<<age<<std::endl;
        std::cout<<name<<std::endl;
    }
};


int main()
{
    Cat cat("Max",10,"black");
    
    assert(cat.color == "black");
    assert(cat.age == 10);
    assert(cat.name == "Max");
    cat.get_info();
}