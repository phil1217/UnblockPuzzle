#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include<vector>
#include<unordered_map>

using namespace std;

class Solver{
private:
    unordered_map<string,Board> visited;
    Block goal;
    Board initialBoard;

    void constructSolution(Board &board);

public:
    vector<Board> solution;
    Solver(Board &board,Block &goal);

    void solve();

};

#endif
