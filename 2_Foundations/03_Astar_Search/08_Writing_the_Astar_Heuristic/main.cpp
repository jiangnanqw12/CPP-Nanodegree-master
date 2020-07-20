#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using std::cout;
using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;

enum class State {kEmpty,kObstacle};


 vector<State> ParseLine(string line) {
    istringstream sline(line);
    vector<State> row;
    int a;
    char b;
    while (sline>>a>>b && b==',')
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


 vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile(path);
  string line;
  vector<vector<State>> board;
  while(getline(myfile,line))
  {
    board.push_back(ParseLine(line));
  }
  return board;
}

// TODO: Write the Heuristic function here.
// Calculate the manhattan distance
int Heuristic(int x1,int y1,int x2,int y2){
  return abs(x1-x2)+abs(y1-y2);
}

/**
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  cout << "No path found!" << "\n";
  return std::vector<vector<State>> {};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   ";
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

#include "test.cpp" // For testing solution

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
}
