#include<string>
#include<iostream>
using std::string;
using std::cout;

class Car
{
    public:
    void PrintCarData()
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    // Method to increment the distance travelled.
    void IncrementDistance()
    {
        distance++;
    }

    // Class/object attributes
    string color;
    int distance = 0;
    int number;
};

int main()
{
    Car car1,car2,car3;
    car1.color="red";
    car1.number=2;
    car1.IncrementDistance();
    car1.PrintCarData();
}