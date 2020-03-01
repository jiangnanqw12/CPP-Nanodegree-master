#include<iostream>
#include"linux_parser.cpp"
#include"linux_parserS.cpp"
using namespace std;
int main()
{
  cout<<LinuxParser::TotalProcesses()<<endl;
  cout<<LinuxParserS::TotalProcesses()<<endl;
  return 0;
}