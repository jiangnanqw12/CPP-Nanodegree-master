#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
    void show()
    {
        cout << "111" << endl;
    }
};
int main()
{
    shared_ptr<A> ptr_1(new A);
    ptr_1->show();
    cout << ptr_1.get() << endl;
    cout << endl;

    shared_ptr<A> ptr_2(ptr_1);
    ptr_2->show();
    cout << ptr_1.get() << endl;
    cout << ptr_2.get() << endl;
    cout << endl;
    shared_ptr<A> ptr_3;
    ptr_3->show();
    cout << ptr_1.get() << endl;
    cout << "2" << endl;
    cout << ptr_3.get() << endl;
    cout << endl;
}
