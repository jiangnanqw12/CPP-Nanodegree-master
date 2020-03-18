#include<iostream>
#include<assert.h>

class Rectangle;
class Square{
    public:
    
    Square(int s){
        side=s;
    }
     void test(){
        std::cout << side << std::endl;
    }
    private:
    friend class Rectangle;
    int side;
};

class Rectangle{
    public:
    Rectangle(Square& s):width(s.side),height(s.side)
    {}
    float Area()
    {
        return width*height;
    }
    private:
    float width;
    float height;
};

int main()
{
    Square s1(4);
    Rectangle r1(s1);
    std::cout<<r1.Area();
    
}
