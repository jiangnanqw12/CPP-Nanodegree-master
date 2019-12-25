

#include<iostream>


template<class T>
T returnMax(T a,T b)
{
    if(a>b)
    return b;
    if(a<b)
    return a;
};
int main()
{
    std::cout<<returnMax(10,2)<<std::endl;
    float f1=1.2,f2=2.2;
    int n1=2,n2=3;
    std::cout<<returnMax(f1,f2)<<std::endl;
    std::cout<<typeid(returnMax(f1,f2)).name()<<std::endl;
    std::cout<<returnMax("abc","cdf")<<std::endl;
    typeid(returnMax("abc","cdf"));
    std::cout<<typeid(returnMax("abc","cdf")).name()<<std::endl;
}