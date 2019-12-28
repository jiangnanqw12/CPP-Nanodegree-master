#include <iostream>
#include<assert.h>
#include <exception>
class Date
{
public:
    Date(int d, int m, int y) : year(y), month(m), day(d) {}
    void SetDate(int y, int m, int d);
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

private:
    int year;
    int month;
    int day;
};
void Date::SetDate(int d, int m, int y)
{
    int day_numbers[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::cout<<"test2"<<std::endl;
    if (y<1||m<1||d<1||m>12||d>day_numbers[m-1])
    {
        std::cout<<"test"<<std::endl;
        throw std::domain_error("wrong");
    }
    Date::year=y;
    Date::month=m;
    Date::day=d;
    
    
}

int main() {
  Date date(12, 12, 2010);
  assert(date.getMonth() == 12);
  Date date2(43, 12, 2010);
  //assert(date2.getDay() != 43);
  date2.SetDate(43,12,2010);
  std::cout<<date.getDay()<<std::endl;
  std::cout<<date.getMonth()<<std::endl;
  std::cout<<date.getYear()<<std::endl;
  std::cout<<date2.getDay()<<std::endl;
  std::cout<<date2.getMonth()<<std::endl;
  std::cout<<date2.getYear()<<std::endl;
  return 0;
}