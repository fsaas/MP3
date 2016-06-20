#include "Flag.h"
#include "GRenderer.h"
#include "GImage.h"
#include "mainProc.h"

Flag::Flag()
{

	//�̹��� �ʱ�ȭ
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_FLAG_Body.png");

	//��ǥ �ʱ�ȭ
	x = 800;
	y = 158;
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
