#include<iostream>

class Student{
    private:
    std::string Name;
    int Grade;
    float Grade_Point_Average;

    public:
    Student(std::string n,int G,float GP)
    {
        Name=n;
        Grade=G;
        Grade_Point_Average=GP;
    }

    std::string GetName();
    int getyear();
    void setname(std::string n);
};


int Student::getyear()
{
    return Student::Grade;
}

void Student::setname(std::string n)
{
    Student::Name=n;
}
// std::string Student::GetName(){
//              return Student::Name;
//          }
std::string Student::GetName()
{
    return Student::Name;
}
// main function
int main(){
    // Test instantiation and getters / setters
    Student student("Stephen", 4, 4.0);
    std::cout << student.GetName() << "\n";
   
}