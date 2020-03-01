#include<iostream>
#include"linux_parser.h"
#include"linux_parserS.h"
using namespace std;
int main()
{
  cout<<LinuxParser::TotalProcesses()<<endl;
  cout<<LinuxParserS::TotalProcesses()<<endl;
  return 0;
}