#pragma once
class GImage;
class GRenderer;
class Player;

class subFlag
{
private:  
	GImage *img;
	Player *player;
	float x;
	float y;

public:
	subFlag(Player* myPlayer);
	~subFlag();
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	void Draw();
	void Update();
	void down();
};

