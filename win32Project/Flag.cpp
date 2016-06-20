#include "Flag.h"
#include "GRenderer.h"
#include "GImage.h"
#include "mainProc.h"

Flag::Flag()
{

	//이미지 초기화
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_FLAG_Body.bmp");

	//좌표 초기화
	x = 800;
	y = 148;
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
}

void Flag::Update()
{

}

void Flag::Draw()
{
	Renderer()->Draw(img, getX(), getY());
}
