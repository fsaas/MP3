#pragma once
class Block;
class BlockManager
{
private:
	Block* block[128];
public:
	BlockManager();
	~BlockManager();
	Block* getBlock(int blockNum);
};

