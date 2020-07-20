#include <iostream>
#include <string>
#include <thread>

void printName(std::string &name, int waitTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from Thread)";
    std::cout << name << std::endl;
}

int main()
{
    std::string name("MyThread");
    std::thread t1(printName, std::ref(name), 50);
    t1.join();
}