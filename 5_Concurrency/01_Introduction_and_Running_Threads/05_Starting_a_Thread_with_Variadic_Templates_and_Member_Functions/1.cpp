#include <iostream>
#include <string>
#include <thread>

void printID(int id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID = " << id << ", name = " << name << std::endl;
}
int main()
{
    int id = 0;
    std::thread t1(printID, id);
    std::thread t2(printIDAndName, ++id, "test");
    std::cout << "main" << std::endl;
    t1.join();
    t2.join();
}