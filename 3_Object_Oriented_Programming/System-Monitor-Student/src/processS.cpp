#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "ProcessS.h"

using std::string;
using std::to_string;
using std::vector;

ProcessS::ProcessS(int pid):pid_(pid)
{

}
// TODO: Return this ProcessS's ID
int ProcessS::Pid() { return pid_; }

// TODO: Return this ProcessS's CPU utilization
float ProcessS::CpuUtilization() { return cpuUtilization_ = LinuxParser::CpuUtilization(pid_); }

// TODO: Return the command that generated this ProcessS
string ProcessS::Command() { return LinuxParser::Command(pid_); }

// TODO: Return this ProcessS's memory utilization
string ProcessS::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this ProcessS
string ProcessS::User() { return LinuxParser::User(pid_); }

// TODO: Return the age of this ProcessS (in seconds)
long int ProcessS::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for ProcessS objects
// REMOVE: [[maybe_unused]] once you define the function
bool ProcessS::operator<(ProcessS const& a) const { return a.cpuUtilization_ < cpuUtilization_; }