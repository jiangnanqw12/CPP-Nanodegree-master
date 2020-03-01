#include<iostream>
#include"linux_parser.cpp"
#include"linux_parserS.cpp"
using namespace std;
int main()
{
  cout<<LinuxParser::CpuUtilization()[0]<<endl;
  cout<<LinuxParserS::CpuUtilization()[0]<<endl;
  return 0;
}