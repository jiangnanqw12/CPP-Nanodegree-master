#include<iostream>
#include<cmath>

#define pi 3.1415926;

class lineSegment{

    public:
    void set_radius(float r){
        radius=r;
    }
    float get_length()
    {
        return radius;
    }
    protected:
    float radius;

};
class Circle{
    public:
    Circle(lineSegment& l):radius_(l){}
    float get_aera()
    {
        return pow(radius_.get_length(),2)*pi;
    }
    
    private:
    lineSegment& radius_;
};


int main()
{
    lineSegment radius;
    radius.set_radius(3);
    Circle c1(radius);
    std::cout<<c1.get_aera()<<std::endl;

}