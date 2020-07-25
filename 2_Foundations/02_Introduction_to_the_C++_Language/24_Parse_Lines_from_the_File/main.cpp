#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

//for String stream to INT
#include <sstream>
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string line){

    vector<int> lineV;
    int a;
    char b;
    istringstream mystream(line);
    while(mystream>>a>>b)
    {
      lineV.push_back(a);
      //cout<<a<<" _ ";
    }
  return lineV;
}


vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  string line;
  vector<int> lineV;
  vector<vector<int>> board;
  if (myfile) {
    
    while (getline(myfile, line)) {
      cout << line << "\n";
      lineV=ParseLine(line);
      board.push_back(lineV);
    }
  }
  
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

#include "test.cpp" // For testing.

int main() {
  ReadBoardFile("1.board");
  TestParseLine(); // For testing.
  // Leave commented out.
  
  PrintBoard(ReadBoardFile("1.board"));
}
