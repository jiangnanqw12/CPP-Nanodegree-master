#include<iostream>
#include"linux_parser.h"
#include"linux_parserS.h"
using namespace std;
int main()
{
  cout<<LinuxParser::Jiffies()<<endl;
  cout<<LinuxParserS::Jiffies()<<endl;
  return 0;
}