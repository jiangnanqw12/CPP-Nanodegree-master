#include <iostream>
#include <string>
#include <thread>

void printName(std::string name, int waitTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    std::cout << "Name (from Thread) = " << name << std::endl;
}

int main()
{
    std::string s1 = "test1";
    std::string s2 = "test2";
    std::thread t1(printName, s1, 50);
    std::thread t2(printName, s2, 100);
    t1.join();
    t2.join();
}