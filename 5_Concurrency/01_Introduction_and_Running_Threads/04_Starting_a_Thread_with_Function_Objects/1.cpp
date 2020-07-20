#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n";
    }
};
int main()
{
    std::thread t((Vehicle()));
    std::cout << "main" << std::endl;
    t.join();
}