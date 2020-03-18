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

class ProcessParser {
  private:
    std::ifstream stream;

  public:
    static string getCmd(string pid);
    static vector<string> getPidList();
    static std::string getVmSize(string pid);
    static std::string getCpuPercent(string pid);
    static long int getSysUpTime();
    static std::string getProcUpTime(string pid);
    static string getProcUser(string pid);
    static vector<string> getSysCpuPercent(string coreNumberg);
    static float getSysActiveCpuTime(vector<string> values);
    static float getSysIdleCpuTime(vector<string> values);
    static float getSysRamPercent();
    static string getSysKernelVersion();
    static int getNumberOfCores();
    static int getTotalThreads();
    static int getTotalNumberOfProcesses();
    static int getNumberOfRunningProcesses();
    static string getOSName();
    static std::string PrintCpuStats(std::vector<std::string> values1,
                                     std::vector<std::string> values2);
    static bool isPidExisting(string pid);
};

std::string ProcessParser::getVmSize(string pid) {
  string line;
  //Declaring search attribute for file
  string name = "VmData";
  float result;

  // Opening stream for specific file
  ifstream stream = Util::getStream((Path::basePath() + pid + Path::statusPath()));

  while (std::getline(stream, line)) {
    // Searching line by line
    if (line.compare(0, name.size(), name) == 0) {
      // slicing string line on ws for values using sstream
      istringstream buf(line);
      istream_iterator<string> beg(buf), end;
      vector<string> values(beg,end);
      //conversion kB -> GB
      std::cout<<values[2]<<std::endl;
      result = (stof(values[1]) / float(1024));
      break;
    }
  }
  return to_string(result);
};
int main()
{
    ProcessParser:: getVmSize("1");
    //vector<string> values2("2","3");
}