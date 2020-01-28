#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <vector>
#include <dirent.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include "ProcessParser.h"
#include "util.h"
#include <unistd.h>
//#include "ProcessParser.h"
using namespace std;
void print_vector(vector<string> &vec);
vector<string> test_path_stream();
vector<string> test_pidlist();
void test_fee();

int main()
{
    
    return 0;
}
void test()
{
    string line;
    ifstream stream("t.txt");
    vector<string> result;
    int index;
    while (getline(stream, line))
    {
        istringstream buf(line);
        istream_iterator<string> beg(buf);
        istream_iterator<string> end;
        vector<string> values(beg, end);
        result = values;
    }
index=line.find("=");
index++;

    print_vector(result);
}
void test_fee()
{
    string line;
    ifstream stream("t.txt");
    vector<string> result;
    int index;
    while (getline(stream, line))
    {
        istringstream buf(line);
        istream_iterator<string> beg(buf);
        istream_iterator<string> end;
        vector<string> values(beg, end);
        result = values;
    }

    print_vector(result);
}

void print_vector(vector<string> &vec)
{
    cout << "vec_print" << endl;
    cout << vec.size() << endl;
    cout << vec[0].size() << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << i << ":" << vec[i] << "  ";
    }
    cout << std::endl;
}

vector<string> test_path_stream()
{
    string path = "/proc/1/status";
    ifstream stream(path);
    string line;
    string name = "VmData";
    vector<string> result;
    //cout<<"1"<<endl;
    //cout<<stream<<endl;

    // getline(stream,line);
    // cout<<line<<endl;

    while (std::getline(stream, line))
    {
        //cout<<"2"<<endl;
        //cout<<line<<endl;
        // if (line.compare(0, name.size(),name) == 0) {
        //         cout<<"3"<<endl;
        //         // slicing string line on ws for values using sstream
        //         istringstream buf(line);
        //         istream_iterator<string> beg(buf), end;
        //         vector<string> values(beg, end);
        //         //conversion kB -> GB
        //         //result = (stof(values[1])/float(1024));//string to float
        //         break;
        //     }

        if (line.compare(0, name.size(), name) == 0)
        {
            cout << "3" << endl;
            cout << line << endl;
            istringstream buf(line);
            istream_iterator<string> beg(buf), end;
            vector<string> values(beg, end);
            result = values;
            break;
        }
    }
    return result;
}

vector<string> test_pidlist()
{
    vector<string> container;
    DIR *dir;
    if (dir = opendir("/proc"))
    {
    };
    while (dirent *dirp = readdir(dir))
    {
        if (dirp->d_type != DT_DIR)
            continue;
        if (all_of(dirp->d_name, dirp->d_name + strlen(dirp->d_name), [](char c) { return std::isdigit(c); }))
        {
            container.push_back(dirp->d_name);
        }
    }

    print_vector(container);
}