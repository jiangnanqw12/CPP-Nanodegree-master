
#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() {

    //////////////////////
    //1D Vector Access
    /////////////////////
    vector<int> a = {0, 1, 2, 3, 4};
    cout<<a[0];
    cout<<std::endl;
    //Getting a Vector's Length
    cout<<a.size()<<"\n";

    ////////////////////////
    //2D Vector Access
    ///////////////////////
    vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};

    cout<<b[1][1]<<"\n";
    //Getting a Vector's Length
    cout<<b.size()<<" "<<b[1].size();

}
