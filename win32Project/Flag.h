#pragma once

class GImage;
class GRenderer;

class Flag
{
private:
	GImage *img;
	float x;
	float y;

public:
	Flag();
	~Flag();
	float getX();
	float getY();
	void Initialize();
	void Update();
	void Draw();

};

