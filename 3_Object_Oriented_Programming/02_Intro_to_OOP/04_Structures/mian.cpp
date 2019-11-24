// Include iostream for output
#include <iostream>
#include<string>

//在c 中的 sturcture 是沒辦法加邏輯判斷的, 導致所有的初值檢查都要放到外面做

struct Student
{
  std::string name;
  int gender;
  int age;
};
// Define a simple structure
struct Date {
  int day;
  int month;
  int year;
};

// Define a main function to instantiate and test
int main()
{
    Date date;
    date.day = 1;
    date.month = 10;
    date.year = 2019;
    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
    Student Harry;
    Harry.name="Harry";
    std::cout<<Harry.name;

    
}
