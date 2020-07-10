#include <iostream>

int main()
{
    int id = 0; // Define an integer variable

    // create lambda
    auto f = [](const int id) {
        std::cout << "id: " << id << std::endl;
    };
    f(1);
}