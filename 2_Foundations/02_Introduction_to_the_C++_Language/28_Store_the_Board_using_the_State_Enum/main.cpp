#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

// TODO: Change the return type to use auto or
// explicitly indicate vector<State>
vector<State> ParseLine(string line) {
    istringstream sline(line);
    // TODO: Change the variable type for row
    // to be a vector<State>
    vector<State> row;
    int a;
    char b;
      // TODO: Modify the line below to push_back
      // a State::kEmpty if n is 0, and push_back
      // a State::kObstacle otherwise.
    while(sline>>a>>b && b== ',')
    {
      
      
      if (a==0)
      {
        row.push_back(State::kEmpty);
      }
      else
      {
        row.push_back(State::kObstacle);
      }
      
    }
    return row;
    
}

// TODO: Modify the return type here as well. Just
// as above, the board will contain State objects
// instead of ints.
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile(path);
  string line;
  vector<State> row;
  vector<vector<State>> board;
  // TODO: Modify the board declarationto store
  // State objects instead of ints.
  while(getline(myfile,line))
  {
  row=ParseLine(line);
  board.push_back(row);
  }
  return board;
   
}

string CellString(State cell) {
  switch(cell)
  {
  case State::kEmpty:
  return "0   ";
  case State::kObstacle:
  //return "⛰️   ";
  return "T   ";
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      // TODO: Modify the line below to call CellString
      // on each element of the board before streaming to cout.
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
  
  
}
