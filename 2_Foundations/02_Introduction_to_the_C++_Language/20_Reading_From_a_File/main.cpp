#include <iostream>
#include <string>
using std::cout;
#include <fstream>

void file_open_testing()
{
std::fstream myfile;
myfile.open("files/1.board");
if (myfile)
{
    cout<<"1"<<"\n";
}
else
{
    cout<<"0"<<"\n";
}

}

void reading_data_from_stream()
{

    std::fstream myfile("files/1.board");
    std::string line;
    while(std::getline(myfile,line))
    {
        cout<<line<<"\n";
    }
    
}




   




/*
Four steps to reading a file:

1.#include <fstream>
2.Create a std::ifstream object using the path to your file.
3.Evaluate the std::ifstream object as a bool to ensure that the stream
    creation did not fail.
4.Use a while loop with getline to write file lines to a string.
*/

int main(){
    file_open_testing();
    reading_data_from_stream();
}
