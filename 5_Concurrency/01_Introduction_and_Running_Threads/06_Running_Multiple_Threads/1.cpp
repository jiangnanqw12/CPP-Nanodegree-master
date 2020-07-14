#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread #" << std::this_thread::get_id()
              << std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++)
    {
        threads.emplace_back(std::thread(printHello));
    }
    for (auto &t : threads)
    {
        t.join();
    }
    return 0;
}
