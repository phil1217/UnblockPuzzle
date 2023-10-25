#include "Board.h"
#include "Block.h"
#include<iostream>
#include<vector>
#include "Solver.h"
#include<bitset>
#include <map>
#include<string>
#include "Hash.h"
#include<unordered_map>
#include<chrono>

using namespace std;

int main(int argc, char *argv[]) {

    //Block(uniqueID,index(Rows | Columns),position(from 0 to BOARD_SIZE - length),blockLength,isHorizontal)

    vector<Block> blocks={
        Block(1,0,0,2,false),
        Block(2,2,2,2,false),
        Block(3,3,2,2,false),
        Block(4,3,4,2,false),
        Block(5,4,0,2,false),
        Block(6,4,2,2,false),
        Block(7,5,0,3,false),

        Block(8,2,0,2,true),
        Block(9,3,0,2,true),
        Block(10,1,1,3,true),
        Block(11,4,4,2,true),
        Block(12,5,4,2,true)
    };

    Block goal(8,2,4,2,true);

    //initial boards
    Board initial(blocks);

    //goal block and its specific position
    Solver solver(initial,goal);

    auto start = chrono::high_resolution_clock::now();

    //start solving
    solver.solve();

    auto finish = chrono::high_resolution_clock::now();

    std::chrono::duration<double> runningTime = finish - start;

    //get solution
    vector<Board> boards = solver.solution;

    for(int i=boards.size()-1;i>=0;i--){
        cout<<"step "<<(boards.size()-i)<<endl;
        for(int j=0;j<boards[i].blocks.size();j++){
            cout<<"Block("<<boards[i].blocks[j].id<<","<<boards[i].blocks[j].index<<","<<boards[i].blocks[j].position<<","<<boards[i].blocks[j].length<<","<<boards[i].blocks[j].isHorizontal<<")\n";
        }
        cout<<"\n";
    }

    cout<<"The total time: "<< runningTime.count()<<endl;
    cout<<"The total steps: "<< boards.size() <<endl;


return 0;
}
