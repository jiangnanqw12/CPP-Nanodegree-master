#include<iostream>


class Rectangle;
class Square{
    public:
    Square(int s){
        side=s;
    }
    private:
    friend class Rectangle;
    int side;
};

class Rectangle{
    
    private:
    float width;
    float height;
}

