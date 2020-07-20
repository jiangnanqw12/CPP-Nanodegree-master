#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using std::vector;
using std::string;

void read_data(std::string path)
{
  std::fstream boardfile;
  boardfile.open(path);
  std::cout<<"ok"<<"\n";
  if(boardfile)
  {
    std::string line;
    vector<vector<int>> board={};
    while(getline(boardfile,line))
    {
      std::cout<<line<<"\n";
      //board.push_back(atoi(line));
    }
    
    
  }
  else
  {
    std::cout<<"error"<<"\n";
  }
  
}
void print_data(std::string path)
{
  std::fstream boardfile(path);
  
}

int main()
{
string file_path = "files/1.board";
read_data(file_path);
}