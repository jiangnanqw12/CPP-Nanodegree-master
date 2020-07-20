#include <iostream>
#include <thread>

int main()
{
    int id = 0; // Define an integer variable

    // starting a first thread (by reference)
    auto f0 = [&id]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "f0 id: " << id << std::endl;
    };
    std::thread t(f0);
    auto f1([&id]() mutable { std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "f1 " << ++id << std::endl; });
    std::thread t2(f1);

    std::cout << "main " << id << std::endl;
    t.join();
    t2.join();
}