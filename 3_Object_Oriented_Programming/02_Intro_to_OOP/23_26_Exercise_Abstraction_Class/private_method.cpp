#include<iostream>
#include<cmath>

class Sphere
{
private:
    /* data */
    float radius;
    double volume=pow(radius,3)*4/3*pi;
    void update(float r)
    {
        if (r>=0)
        {
            radius=r;
            volume=pow(radius,3)*4/3*pi;
        }
    }
public:
    const float pi=3.14159;
    Sphere(float r)
    {
        update(r);
    };
    float getR() const
    {
        return radius;
    }
    float getV() const
    {
        return volume;
    }
    void update_radius(float r)
    {
        update(r);
    }
};

int main()
{
    Sphere s(5);
    std::cout<<s.getR()<<std::endl;
    std::cout<<s.getV()<<std::endl;
    s.update_radius(3);
    std::cout<<s.getR()<<std::endl;
    std::cout<<s.getV()<<std::endl;
    return 0;
}
