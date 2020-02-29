#include<iostream>
#include"linux_parser.h"
#include"linux_parserS.h"
using namespace std;
int main()
{
  cout<<LinuxParser::ActiveJiffies(1)<<endl;
  cout<<LinuxParserS::ActiveJiffies(1)<<endl;
  return 0;
}