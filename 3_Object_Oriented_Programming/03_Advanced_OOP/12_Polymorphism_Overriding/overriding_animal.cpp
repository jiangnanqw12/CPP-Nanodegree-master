#include<iostream>

class Animal{
    public:
    virtual std::string Talk() const;
};

class Cat{
    public:
    std::string Talk() const
    {
        std::cout<<"miao"<<std::endl;
        return "miao";
    }
};
class Dog:public Cat{
    public:
    std::string Talk() const
    {
        std::cout<<"wang"<<std::endl;
        return "wang";
    }
};

int main()
{
    Cat c1;
    c1.Talk();
    Dog d1;
    d1.Talk();
    c1.Talk();
}