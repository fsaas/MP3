#pragma once
class Block;
class BlockManager
{
private:
	Block* block[160];
public:
	BlockManager();
	~BlockManager();
	Block* getBlock(int blockNum);
};

