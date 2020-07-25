/*
Formatting the Printed Board
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   0    0   0  ⛰️   0

The board will eventually have more than two cell states as the program becomes more complicated,
and it would be nice to add formatting to the printed output of the board to ensure readability as the number of board states increases.

To accommodate more board states and facilitate print formatting, we have provided the State enum
with enumerator values kEmpty and kObstacle. In this exercise,
you will write a CellString function which converts each State to an appropriate string.
In the next exercise, we will update the program to use the enum values and CellString function.
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;

enum class State{kEmpty, kObstacle};

vector<int> ParseLine(string line) {
    istringstream line_s(line);
    int a;
    char b;
    vector<int> data;
    while(line_s>>a>>b)
    {
      data.push_back(a);
    }
    return data;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "
string CellString(State cell){

    switch (cell)
    {
    case State::kEmpty:
      return "0   ";
      break;
    case State::kObstacle:
      return "⛰️   ";
      break;
    
    default:
      break;
    }

}


void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      //cout << board[i][j];
      State cell;
      if(board[i][j]==0)
      {
        cell=State::kEmpty;
      }
      else
      {
        cell=State::kObstacle;
      }
      cout<<CellString(cell);
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}
