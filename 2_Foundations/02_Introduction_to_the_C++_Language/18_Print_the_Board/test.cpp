#include <iostream>
#include <vector>
#include "add.h"
using std::cout;
using std::vector;




int main(){
    vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0}};

    PrintBoard(board);
}
