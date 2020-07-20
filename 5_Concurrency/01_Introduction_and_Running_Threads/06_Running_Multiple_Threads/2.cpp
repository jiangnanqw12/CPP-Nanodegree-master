#include <random>
#include <thread>
#include <vector>
#include <iostream>

int main()
{
    // create threads
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 10; ++i)
    {
        auto f = [i]() { std::this_thread::sleep_for(std::chrono::milliseconds(i * 10));
                                      std::cout
                                  << "test" << i << std::endl; };
        std::thread t(f);
        t.join();
    }
}