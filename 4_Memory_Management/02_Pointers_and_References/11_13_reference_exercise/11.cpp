#include <iostream>
void test();
int main()
{
    test();
    return 0;
}
void test()
{

    std::string str = "Hello World";

    const char *ptr = str.c_str();

    std::cout
        << "string is: " << ptr << std::endl;
    std::cout << "string addrs is: " << &ptr << std::endl;

    int a = 10;
    int *n = &a;
    int *n2 = new int(10);
    std::cout
        << n << std::endl;
    std::cout
        << n2 << std::endl;
    char *tmp = new char(10);
    std::cout << "tmp is" << tmp << std::endl;
}