#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line;
  string resultTotal = "";
  string resultFree = "";
  string name1 = "MemTotal";
  string name2 = "MemFree";
  ifstream fstream(kProcDirectory + kMeminfoFilename);
  while (getline(fstream, line)) {
    if (line.compare(0, name1.size(), name1) == 0) {
      istringstream buf(line);
      istream_iterator<string> beg(buf), end;
      vector<string> values(beg, end);
      resultTotal = values[1];
      // std::cout<<resultTotal<<std::endl;
    }
    if (line.compare(0, name2.size(), name2) == 0) {
      istringstream buf(line);
      istream_iterator<string> beg(buf), end;
      vector<string> values(beg, end);
      resultFree = values[1];
      // std::cout<<resultFree<<std::endl;
    }
  }
  float memFreeGB = stol(resultFree) / (1024 * 1024);
  float memTotalGB = stol(resultTotal) / (1024 * 1024);

  return (memTotalGB - memFreeGB) / memTotalGB;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() {
  string line;
  ifstream fstream(kProcDirectory + kUptimeFilename);
  getline(fstream, line);
  istringstream buf(line);
  istream_iterator<string> beg(buf), end;
  vector<string> values(beg, end);
  return stol(values[0]);
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  string line;
  ifstream fstream(kProcDirectory + kStatFilename);
  string cpu;
  long user;
  long nice;
  long system;
  long idle;
  long iowait;
  long irq;
  long softirq;
  long steal;
  long guess;
  long guessnice;
  if (fstream.is_open()) {
    getline(fstream, line);
    istringstream linestream(line);

    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guess >> guessnice;
  }
  long totalUserTime = user - guess;
  long totalNiceTime = nice - guessnice;
  long totalIdleTime = idle + iowait;
  long totalSystem = system + irq + softirq;
  long totalVirtualTime = guess + guessnice;

  return totalUserTime + totalNiceTime + totalIdleTime + totalSystem +
         totalVirtualTime;
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
  ifstream fstream(kProcDirectory + to_string(pid) + kStatFilename);
  if (fstream.is_open()) {
    long utime;
    long stime;
    long cutime;
    long cstime;
    string ignore;
    long starttime;
    string line;
    getline(fstream, line);
    istringstream linestream(line);
    for (int i = 0; i < 13; i++) linestream >> ignore;
    linestream >> utime >> stime >> cutime >> cstime;
    for (int i = 0; i < 4; i++) linestream >> ignore;
    linestream >> starttime;
    return utime + stime + cutime + cstime + starttime;
  }
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  std::ifstream filestream(kProcDirectory + kUptimeFilename);
  long upTime = 0;
  long idleTime;
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> upTime >> idleTime;
  }
  return 0;
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  string os, kernel;
  string line;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    std::string cpu;
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long guess;
    long guessnice;
    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guess >> guessnice;
    long totalUserTime = user - guess;
    long totalNiceTime = nice - guessnice;
    long totalIdleTime = idle + iowait;
    long totalSystem = system + irq + softirq;
    long totalVirtualTime = guess + guessnice;
    return totalIdleTime;
  }
  return 0;
}

vector<LinuxParser::CpuKPI> LinuxParser::CpuUtilPercentage() {
  ifstream fstream(kProcDirectory + kStatFilename);
  string line;
  vector<LinuxParser::CpuKPI> returnVec;
  while (getline(fstream, line)) {
    istringstream linestream(line);
    string cpu;

    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long guess;
    long guessnice;
    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guess >> guessnice;
    if (cpu.substr(0, 3) != "cpu") return returnVec;
    CpuKPI CpuS;
    long totalIdleTime = idle + iowait;
    long totalNoIdleTime = user + nice + system + irq + softirq;
    CpuS.idleTime = totalIdleTime;
    CpuS.totalTime = totalIdleTime + totalNoIdleTime;
    returnVec.emplace_back(CpuS);
  }
  return returnVec;
}
// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  vector<CpuKPI> previousVec = CpuUtilPercentage();
  sleep(1);
  vector<CpuKPI> currentVec = CpuUtilPercentage();
  vector<string> reutrnVec;
  for (int i = 0; i < currentVec.size(); i++) {
    long idleDelta = currentVec[i].idleTime - previousVec[i].idleTime;

    long totalDelta = currentVec[i].totalTime - previousVec[i].totalTime;
    double CpuU = (totalDelta - idleDelta) * 1.0 / totalDelta * 1.0;
    reutrnVec.emplace_back(to_string(CpuU));
  }
  // std::cout<<idleDelta<<std::endl;
  // std::cout<<totalDelta<<std::endl;
  return reutrnVec;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  ifstream fstream(kProcDirectory + kStatFilename);
  string line;
  string key;
  int num=0;
  bool processesNumberFound=false;

  while (getline(fstream, line)&&!processesNumberFound) {
    
    istringstream linestream(line);
    linestream>>key;
    //std::cout<<key<<std::endl;
    if (key=="processes")
    {
      
      linestream>>num;
      processesNumberFound=true;
    }
  }
  return num;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { return 0; }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid [[maybe_unused]]) { return 0; }