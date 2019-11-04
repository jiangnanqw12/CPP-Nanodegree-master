#include<string>
#include<iostream>
using std::string;
using std:: cout;
class Car {
    public:
    void PrintCarData()
        {
            cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
        }

    void IncrementDistance()
        {
            distance++;
        }
    Car(string c,int n)
    {
        color=c;
        number=n;
    }
    string color;
    int number;
    int distance=0;
    
};

int main()
{
    Car car_1=Car("red",1);
    Car car_2=Car("blue",2);
    car_1.IncrementDistance();
    car_1.PrintCarData();
    car_2.PrintCarData();
}
