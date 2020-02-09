
#include"ProcessParser.h"
#include"SysInfo.h"


void writeSysInfoToConsole(SysInfo sys, WINDOW* sys_win)
{
    sys.setAttributes();

    mvwprintw(sys_win,2,2,getCString(( "OS: " + sys.getOSName())));
    mvwprintw(sys_win,3,2,getCString(( "Kernel version: " + sys.getKernelVersion())));
    mvwprintw(sys_win,4,2,getCString( "CPU: "));
    wattron(sys_win,COLOR_PAIR(1));
    wprintw(sys_win,getCString(Util::getProgressBar(sys.getCpuPercent())));
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,5,2,getCString(( "Other cores:")));
    wattron(sys_win,COLOR_PAIR(1));
    std::vector<std::string> val = sys.getCoresStats();
    for (int i = 0; i < val.size(); i++) {
        mvwprintw(sys_win,(6+i),2,getCString(val[i]));
    }
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,10,2,getCString(( "Memory: ")));
    wattron(sys_win,COLOR_PAIR(1));
    wprintw(sys_win,getCString(Util::getProgressBar(sys.getMemPercent())));
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,11,2,getCString(( "Total Processes:" + sys.getTotalProc())));
    mvwprintw(sys_win,12,2,getCString(( "Running Processes:" + sys.getRunningProc())));
    mvwprintw(sys_win,13,2,getCString(( "Up Time: " + Util::convertToTime(sys.getUpTime()))));

}