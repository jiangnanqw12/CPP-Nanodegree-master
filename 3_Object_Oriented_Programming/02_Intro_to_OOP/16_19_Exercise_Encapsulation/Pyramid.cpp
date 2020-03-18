//pyramid
#include <iostream>

class pyramid
{
private:
    double base_length;
    double base_width;
    double height;

public:
    pyramid(double l, double w, double h)
    {
        base_length = l;
        base_width = w;
        height = h;
    }
    double get_length() const;
    double get_width() const;
    double get_height() const;
    void set_length(double l);
    void set_width(double w);
    void set_height(double h);
    double get_volume();
    double get_surface();
    bool Is_Positive(double data);
};

double pyramid::get_length() const
{
    return pyramid::base_length;
}
double pyramid::get_width() const
{
    return pyramid::base_width;
}
double pyramid::get_height() const
{
    return pyramid::height;
}
void pyramid::set_length(double l)
{
    pyramid::base_length = l;
}
void pyramid::set_width(double w)
{
    pyramid::base_width = w;
}
void pyramid::set_height(double h)
{
    pyramid::height = h;
}

double pyramid::get_volume()
{
    return pyramid::base_width * pyramid::base_length * pyramid::height * 1 / 3;
}
double pyramid::get_surface()
{
    return 0;
}
bool pyramid::Is_Positive(double data)
{
    if (data >= 0)
        return 1;
    return 0;
}
int main()
{
    pyramid p(1, 1, 1);
    std::cout << p.get_volume() << std::endl;
    
    std::cout<<p.Is_Positive(p.get_height())<<std::endl;
    std::cout<<p.Is_Positive(-1)<<std::endl;

}
