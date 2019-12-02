#include<iostream>
#include<string>
#include<cstring>

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

void Car::set_brand(std::string brand)
{
    Car::brand =new char[brand.length()+1];
    strcpy(Car::brand,brand.c_str());
}
int Car::get_power() const
{
    return Car::horsepower;
}
int Car::get_weight() const
{
    return Car::weight;
}
std::string Car::get_brand() const{
    std::string brand_name="brand_name: ";
    brand_name+=Car::brand;
    return brand_name;
}

// Test in main()
int main() {
    Car car;
    car.set_brand("peugeot");
    std::cout << car.get_brand() << "\n";
}