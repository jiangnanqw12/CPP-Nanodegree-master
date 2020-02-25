#include<iostream>
#include"linux_parser.h"
#include"linux_parserS.h"
using namespace std;
int main()
{
  cout<<LinuxParser::MemoryUtilization()<<endl;
  cout<<LinuxParserS::MemoryUtilization()<<endl;
  return 0;
}