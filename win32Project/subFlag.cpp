#include "subFlag.h"
#include "GImage.h"
#include "GRenderer.h"
#include "mainProc.h"
#include "Player.h"


subFlag::subFlag(Player* myPlayer)
{

	//이미지 초기화
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_FLAG.bmp");
	player = myPlayer;
	//좌표 초기화
	x = 850;
	y = 148;
}


subFlag::~subFlag()
{
}

float subFlag::getX()
{
	return x;
}

float subFlag::getY()
{
	return y;
}

void subFlag::setX(float given)
{
	x = given;
}

void subFlag::setY(float given)
{
	y = given;
}

void subFlag::Draw()
{
	Renderer()->Draw(img, getX(), getY());
}

void subFlag::Update()
{
	if (player->getX() > 795 && player->getX() < 825)
		down();
}

void subFlag::down()
{
	if(getY()<600)
	{
		setY(getY() + 2);
	}
}
