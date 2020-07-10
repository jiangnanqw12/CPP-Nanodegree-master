#include <iostream>
int main()
{
    int id = 1;

    auto f0 = [id]() { std::cout << "test " << id << std::endl; };
    auto f1 = [&id]() { std::cout << "test " << id << std::endl; };
    auto f2 = [id]() mutable { std::cout << "test " << ++id << std::endl; };

    f0();
    f1();
    f2();
}