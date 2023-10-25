#include "Solver.h"
#include<deque>
#include<iostream>

using namespace std;

Solver::Solver(Board &board,Block &goal):initialBoard(board),goal(goal){}

void Solver::solve(){
    deque<Board> boards;
    boards.push_back(initialBoard);
    Board board;

    while(!boards.empty()){

        board = boards.front();
        boards.pop_front();

         board.identifier = board.getHash();

         if(visited.find(board.identifier) == visited.end()){

             if(board.isCompleted(board.blocks[goal.id - 1])){
                constructSolution(board);
                return;
            }

            visited[board.identifier] = board;

            for(int i=0;i<board.blocks.size();i++){

                for(int j=UP;j<=DOWN;j++){

                    if(board.isMovable(board.blocks[i],j)){

                        Board temp = board;
                        temp.moveBlock(i,j);
                        temp.referrer = board.identifier;

                        boards.push_back(temp);
                    }

                }

            }

         }
    }
}


void Solver::constructSolution(Board &board){

    solution.push_back(board);

    while(!board.referrer.empty()){

        board = visited[board.referrer];
        solution.push_back(board);

    }

    visited.clear();
}
