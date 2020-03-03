#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "processS.h"
#include "processorS.h"
#include "system.h"
#include "linux_parser.h"
using std::set;
using std::size_t;
using std::string;
using std::vector;


// TODO: Return the system's CPU
processorS& System::Cpu() { 
    
    return cpu_;  
}

System::System()
{
    std::vector<int> pids = LinuxParser::Pids();
    for(auto i:pids) {
        processS currentprocessS(i);
        processSes_.emplace_back(currentprocessS);
    }    
}
// TODO: Return a container composed of the system's processSes
vector<processS>& System::processSes() { 
    processSes_.clear();
    std::vector<int> pids = LinuxParser::Pids();
    for(auto i:pids) {
        processS currentprocessS(i);
        processSes_.emplace_back(currentprocessS);
    }
    return processSes_; 
    }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TODO: Return the number of processSes actively running on the system
int System::RunningprocessSes() { return LinuxParser::RunningprocessSes(); }

// TODO: Return the total number of processSes on the system
int System::TotalprocessSes() { return LinuxParser::TotalprocessSes(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }