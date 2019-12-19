
#include<iostream>
#include <typeinfo>
//#include<string>
template<typename u,typename t=int>
class A{
    public:
    u x;
    t y;
    //typeid(int).name();
    A(){
        std::cout<<typeid(x).name()<<std::endl;
    std::cout<<typeid(y).name()<<std::endl;

    }
    
    

};
template<typename u>
u add(u x,u y)
{
    return x+y;
}

template<typename v>
v add2(v x,v y)
{
    return x+y;
}

int main()
{
    A <float> a1;
    A<float,double> a2;
    std::cout<<add<double>(12.0,11)<< std::endl;
    std::cout<<add2<std::string>("11","22")<<std::endl;
}