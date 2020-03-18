#include<iostream>
class ParentClass{
    public:
    int a=1;
    protected:
    int b=2;
    private:
    int c=3;
};

class ChildClass1:public ParentClass{
    public:
    int setb()
    {
        b=33;
        
        std::cout<<b<<std::endl;
    }
};
class ChildClass2:protected ParentClass{

};
class ChildClass3:private ParentClass{
   public:
    int setb()
    {
        b=33;
        
        std::cout<<b<<std::endl;
    }
};
int main()
{
    ChildClass1 c1;
    std::cout<<c1.a;//public
    c1.setb();
    //std::cout<<c1.b;//protected
    ChildClass2 c2;
    //std::cout<<c2.a;//protected
    //std::cout<<c2.b;//protected
    ParentClass p1;
    p1.a;
    ChildClass3 c3;
    c3.setb();
    
}