#include <iostream>
void test();
void test2();
void test3();
char *addSpaces(char &);
int main()
{
    test3();
    return 0;
}
char *addSpaces(const char *ptr)
{
    char *CharTest = new char(sizeof(ptr) * 2);
    std::cout << CharTest << std::endl;
    char *start = CharTest;
    while (*ptr != '\0')
    {
        *CharTest++ = *ptr++;
        *CharTest++ = ' ';
    }

    return start;
}
void test3()
{
    //question1 char() char[]
    std::string str = "Hello World";
    const char *ptr = str.c_str();
    char *start = addSpaces(ptr);
    std::cout << start << std::endl;
}
void test2()
{
    char *temp1 = new char(10);
    printf("%s", temp1);
    std::cout
        << "tmp is" << temp1 << std::endl;
    std::cout << "tmp addrs is" << &temp1 << std::endl;
    std::string str_test = "Hello World";
    char *temp2 = new char(sizeof(str_test) * 2);
    std::cout << "temp2 is" << temp2 << std::endl;
    const char *ptr = str_test.c_str();
    std::cout << "ptr is" << ptr << std::endl;
    char *temp3 = new char(sizeof(ptr) * 2);
    std::cout << "temp3 is" << temp3 << std::endl;
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
}
