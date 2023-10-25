#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include <vector>
#include <string>

using namespace std;

class Board{

public:
    int cells[BOARD_SIZE][BOARD_SIZE] = {{0}};

    Board(vector<Block> &blocks);

    Board();

    bool isCompleted(Block &block);

    bool isMovable(Block &block,int direction);

    void moveBlock(int index,int direction);

    void insert(Block &block,int id = -1);

    string getHash();

    string referrer;
    string identifier;
    vector<Block> blocks;
};

#endif

