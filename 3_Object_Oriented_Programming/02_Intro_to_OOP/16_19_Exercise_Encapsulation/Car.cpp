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

Car::Car(/* args */)
{
}

Car::~Car()
{
}
