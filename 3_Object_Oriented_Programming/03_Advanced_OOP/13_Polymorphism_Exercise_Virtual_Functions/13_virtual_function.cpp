/*
Exercise: Virtual Functions

Polymorphism is one of the crucial components of OOP within C++. In this lab,
you'll use virtual methods and see their role in class interfaces and in the process of inheritance.




Virtual methods are declared (and possibly defined) in a base class, and are meant
to be overridden by derived classes. This approach creates interfaces for your classes at the base level.

=> Virtual methods 專門被宣告在base class 裡面, 就是打算讓 derived class  個別去實做
=> 在base class 只是定義要做的界面
=> 如果沒加 const = 0 在最後, 你在base class 可實做可不實做, 如果加了 const = 0, 在base class 可以留下空白, 就只是個prototypes
=> 加了 const = 0 表示一定要有個dervied class 實做




Here, you'll start with a Shape class as the base class for geometrical 2D entities.
Geometrical shapes (closed curves) can be described by an area and the length of their perimeter.
area and perimeter_length should be methods of the base class interface.

You'll declare each of these as virtual functions with a const = 0 flag to identify them as prototypes in the base class like this:

    class Shape {
        public:
            Shape() {}
            virtual double Area() const = 0;
            virtual double PerimeterLength() const = 0;
    };
We said that in the base class, virtual methods can but do not have to be implemented.
If we delegate with instruction = 0 we are notifying compiler that this (base) class doesn’t
have virtual method implementation but every other derived class is required to implement this method.



要實做的 derived class 要用 下面的語法

virtual double Function() const override{

}




OBJECTIVES
    1.Create base class called Shape.
    2.Chose mutual characteristics of every shape in geometry.
    3.Divide it in individual logical responsibilities.
    4.Design methods for base class and make them pure virtual functions const = 0.
    5.Write the derived classes.
        Inherit parent Shape class.
        Write derived implementation of overridden base methods.
    6.Test in main()

*/


// include iostream for printing
#include<iostream>
#include<cmath>
#define Pi 3.1415926
class Shape{
    public:
    Shape(){}
    virtual double Area() const=0;
    virtual double Perimeter() const=0;
};

class Rectangle:public Shape{
    public:
    Rectangle(double h,double l):height(h),length(l){}
        
    virtual double Area() const override{
        return height*length;
    }
    virtual double Perimeter()const override{
        return 2*(height+length);
    }
    private:
    double height;
    double length;
};
class Circle:public Shape{
    public:
    Circle(double r):radius(r){}
    virtual double Area() const override{
        return Pi*pow(radius,2);
    }
    virtual double Perimeter() const override{
        return 2*Pi*radius;
    }
    private:
    double radius=0;
};

int main()
{
    Rectangle r1(10,5);

    std::cout<<r1.Area()<<std::endl;
    Shape * * shape=new Shape*[2];
    shape[1]=new Rectangle(6,9);
    shape[0]=new Circle(12.3);
    std::cout<<shape[1]->Area()<<std::endl;

}





//
