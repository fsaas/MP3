#include "Flag.h"
#include "mainProc.h"

Flag::Flag()
{
}


Flag::~Flag()
{
}

float Flag::getX()
{
	return x;
}

float Flag::getY()
{
	return y;
}

void Flag::Initialize()
{
	//이미지 초기화
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_FLAG_Body.bmp");

	//좌표 초기화
	x = 800;
	y = 128;
}

void Flag::Update()
{

}

void Flag::Draw()
{
	Renderer()->Draw(img, getX(), getY());
}
