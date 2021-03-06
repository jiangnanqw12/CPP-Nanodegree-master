/*
Polymorphism
Polymorphism is means "assuming many forms".

In the context of object-oriented programming, polymorphism) describes a paradigm in which a
function may behave differently depending on how it is called.

In particular, the function will perform differently based on its inputs.

Polymorphism can be achieved in two ways in C++: overloading and overriding. In this exercise we will focus on overloading.


多型:
一個function 可以根據他的input, 有不同的表現

可以達成這個行為, 在c++中有兩種作法
    1. overloading (compile time polymorphism)
        a.function overloading
        b.operator overloading
    2. overriding (runtime polymorphism)
        a.virtual function
*/



/*
這邊先講 overloading

Overloading : 不同input, 同個function name


In C++, you can write two (or more) versions of a function with the same name.

This is called "overloading". Overloading requires that we leave the function name the same,
but we modify the function signature. For example, we might define the same function name
with multiple different configurations of input arguments.

This example of "class Date" overloads:

*/

////////////////////////////
// 在 class 內 做 overloading
////////////////////////////
#include<ctime>
#include<iostream>
class Date{
    public:
    Date(int day,int month,int year):day_(day),month_(month),year_(year){}
    Date(int day,int month):day_(day),month_(month)
    {
        time_t t=time(NULL);
        tm* timePtr=localtime(&t);
        year_=timePtr->tm_year;
    }
    void get_info()
    {
        std::cout<<year_<<" "<<month_<<" "<<day_<<std::endl;
    }
    private:
    int day_;
    int month_;
    int year_;
};

// int main()
// {
//     Date d1{1,1,1992};
//     d1.get_info();
//     Date d2{1,1};
//     d2.get_info();
//     return 0;
// }


////////////////////////
// overloading 也可以在 class 外面
////////////////////////

/*
Overloading can happen outside of an object-oriented context, too.
In this exercise, you will practice overloading a normal function that is not a class member.

    1.Create a function hello() that outputs, "Hello, World!"
    2.Create a class Human.
    3.Overload hello() by creating a function hello(Human human). This function should output, "Hello, Human!"
    4.Create 2 more classes and use those classes to further overload the hello() function.

*/

#include <iostream>
#include <string>

//create dummuy class for testing
class Human {};
class Dog {};
class Cat {};


// TODO: Write hello() function

void hello()
{
    std::cout<< "Hello,World"<<std::endl;
}
// TODO: Overload hello() three times
void hello(std::string name){
    std::cout<<"hello: "<<name<<std::endl;
}
void hello(std::string name,int id1){
    std::cout<<"hello: "<<name<<" id1: "<<id1<<std::endl;
}

//收其他的class 型別也可以
void hello(Human& human){
    std::cout<<"hello: "<<"human"<<std::endl;
}

void hello(Dog Dog){
    std::cout<<"hello: "<<"dog"<<std::endl;
}


// TODO: Call hello() from main()


int main(){
    
    hello();
    Human h;
    hello("jerry");
    hello("jerry",4);
    hello(h);
    hello(Dog());
    

   
}
