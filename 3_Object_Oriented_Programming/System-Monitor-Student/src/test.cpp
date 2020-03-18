#include<iostream>
#include"linux_parser.h"
//#include"format.h"

using namespace std;
int main()
{
  
  //cout<<Format::ElapsedTime(3600)<<endl;
  string test;
  string line;
  string num,num2="tt",num3="aa";
  string processes;
  std::ifstream fstream(LinuxParser:: kProcDirectory + LinuxParser:: kStatFilename);
  
  while(getline(fstream,line))
  {
    stringstream linestream(line);
    stringstream linestream2;
    linestream>>processes;
    if (processes =="processes")
    {
      linestream>>num;
      linestream2<<num3;
      linestream2>>test;
      linestream2<<num3;
      linestream2>>num;
    }

  }
  
  cout<<test<<" "<<num<<endl;

  
  return 0;
}

  