#pragma once
class Block;
class BlockManager
{
private:
	Block* block[127];
public:
	BlockManager();
	~BlockManager();
	Block* getBlock(int blockNum);
};

