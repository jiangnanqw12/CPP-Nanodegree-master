#include<iostream>

class Car
{
private:
    /* data */
    int horsepower;
    int weight;
    char *brand;
public:
    void set_power(int horsepower);
    void set_weight(int weight);
    void set_brand(std::string brand);
    int get_power() const;
    int get_weight() const;
    std::string get_brand() const;
};

void Car::set_power(int horsepower)
{
    Car::horsepower=horsepower;
}

void Car::set_weight(int weight)
{
    Car::weight=weight;
}

void set_brand(std::string brand)
{
    
}
int Car::get_power() const
{
    return Car::horsepower;
}
int Car::get_weight() const
{
    return Car::weight;
}
std::string get_brand() const{
    retun ;
}