#ifndef BLOCK_H
#define BLOCK_H

#include "globals.h"

class Block{
public:
    Block(int id,int index,int position,int length,bool isHorizontal);

    Block();

    void move(int direction);

    int id;
    int index;
    int position;
    int length;
    bool isHorizontal;
};

#endif
