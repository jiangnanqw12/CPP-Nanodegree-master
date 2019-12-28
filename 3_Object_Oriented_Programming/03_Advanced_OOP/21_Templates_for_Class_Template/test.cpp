#include<iostream>
#include<vector>

template<typename T>
class Container{
   private:
        int s;
        std::vector<T> arr;
    public:
        Container():s(0){
            arr.clear();
        }
        int size(void)
        {
            return Container::s;
        }
        void add(T n)
        {
            arr.push_back(n);
            s++;
        }
        void print()
        {
            for( int i=0;i<s;i++)
            //for (T c:arr)
            {
                std::cout<<arr[i]<<" ";
            }
                std::cout<<std::endl;
        }
};


int main()
{
    Container<double> obj; // Partial deduction: element type is specified
    //std::cout<<"1"<<std::endl;
    obj.add(2.00329132);
    obj.print();
    obj.add(8.83);
    obj.print();
    // TARGET OUTPUT:
    /*
        2.00329
        Size is:1
        2.00329 8.83
        Size is:2
    */


    //一個class 可以應付多種 data type
    Container<char> obj2; // Partial deduction: element type is specified
    obj2.add('A');
    obj2.print();
    obj2.add('b');
    obj2.print();
    /*

    A
    Container::size: 1
    A b
    Container::size: 2


    */


    return 0;
}