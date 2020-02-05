#include <algorithm>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include "util.h"
#include "constants.h"
#include "ProcessParser.h"
#include "process.h"
using namespace std;
void print_vector(vector<string> &vec);
vector<string> test_path_stream();
vector<string> test_pidlist();
void test_fee();
void testreadFile();
void testProcess();

int main()
{

    //testProcess();
    return 0;
}
void testProcess()
{
    
    
    Process p1("1");
    //p1.setPid(1);
    cout<<"t"<<endl;
    cout<<p1.getPid()<<endl;
    string t2=p1.getProcess();
    cout<<t2;
}
void testreadFile()
{
    string line;
    ifstream stream("t.txt");

    int index;
    while (getline(stream, line))
    {
        istringstream buf(line);
        istream_iterator<string> beg(buf);
        istream_iterator<string> end;
        vector<string> values(beg, end);
    }
    index = line.find("=");
    index++;
    string result = line.substr(index);
    //cout << "begin"<<result.begin()<< endl;

    result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
    cout << result[0] << endl;

    //print_vector(result);
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