#include "Block.h"

using namespace std;

Block::Block(int id,int index,int position,int length,bool isHorizontal):id(id),
    index(index),position(position),length(length),isHorizontal(isHorizontal){

}

Block::Block(){}

void Block::move(int direction){
    switch(direction){
    case LEFT:
    case DOWN:
            this->position--;
        break;
    case RIGHT:
    case UP:
            this->position++;
        break;
    default:
        break;
    }
}
