#pragma once
#include "Block.h"

class BlockManager
{
private:
	Block* block[160];
public:
	BlockManager();
	~BlockManager();
	Block* getBlock(int blockNum);
};

