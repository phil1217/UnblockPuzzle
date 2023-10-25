#include "Board.h"

using namespace std;

Board::Board(vector<Block> &blocks):blocks(blocks){
    for(int i=0;i<blocks.size();i++){
        insert(blocks[i]);
    }

}

Board::Board(){}

void Board::moveBlock(int index,int direction){
        insert(blocks[index],0);

        blocks[index].move(direction);

        insert(blocks[index]);
}


string Board::getHash() {
    string hash = string();
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            hash = hash + to_string(this->cells[i][j]);
        }
    }
    return hash;
}

bool Board::isCompleted(Block& block) {
    int heroIndex = block.position + block.length;
    for (int i = heroIndex; i < BOARD_SIZE; ++i) {
        if (!(cells[block.index][i]==0)) {
            return false;
        }
    }

    return true;
}

bool Board::isMovable(Block &block, int direction) {
    int index = (direction == LEFT || direction == DOWN) ? block.position - 1 : block.position + block.length;

    if (index >= 0 && index < BOARD_SIZE) {
        if (block.isHorizontal) {
            return cells[block.index][index] == 0;
        } else {
            return cells[index][block.index] == 0;
        }
    }

    return false;
}

void Board::insert(Block &block,int id){

    int start = block.position;
    int end = start+block.length;

    if(id == -1){
        id = block.id;
    }

    for(int i = start;i<end;i++){

        if(block.isHorizontal){
            cells[block.index][i] = id;

        }else{
            cells[i][block.index] = id;
        }
    }
}

