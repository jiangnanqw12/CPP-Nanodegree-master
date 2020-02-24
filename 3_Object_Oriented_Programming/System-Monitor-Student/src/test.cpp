#include<iostream>
#include"linux_parser.h"
using namespace std;
long LinuxParser::UpTime();
float LinuxParser::MemoryUtilization();
int main()
{
    cout<<LinuxParser::MemoryUtilization()<<endl;
    return 0;
}
float LinuxParser::MemoryUtilization() 
{ 
  string line;
  string resultTotal="";
  string resultFree="";
  string name1="MemTotal:";
  string name2="MemFree:";
  ifstream fstream(kProcDirectory+kMeminfoFilename);
  while(getline(fstream,line))
  {
    if (line.compare(0,name1.size(),name1)==0)
    {
      
      istringstream buf(line);
      istream_iterator<string> beg(buf),end;
      vector<string> values(beg,end);
      resultTotal=values[1];
      
    }
    if (line.compare(0,name2.size(),name2)==0)
    {
      
      istringstream buf(line);
      istream_iterator<string> beg(buf),end;
      vector<string> values(beg,end);
      resultFree=values[1];
    }

  }
  return stof(resultTotal)-stof(resultFree); }

long LinuxParser::UpTime() 
{ 
  string line;
  ifstream fstream(kProcDirectory+kUptimeFilename);
  getline(fstream,line);
  istringstream buf(line);
  istream_iterator <string> beg(buf),end;
  vector<string> values(beg,end);
  return stol(values[0]); 
  }