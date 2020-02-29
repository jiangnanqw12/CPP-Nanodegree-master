#include<iostream>
#include"linux_parser.h"
#include"linux_parserS.h"
using namespace std;
int main()
{
  cout<<LinuxParser::CpuUtilization()[0]<<endl;
  cout<<LinuxParserS::CpuUtilization()[0]<<endl;
  return 0;
}