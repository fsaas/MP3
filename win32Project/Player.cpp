#include "Player.h"
#include "mainProc.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setX(float givenX)
{
	x = givenX;
}
void Player::setY(float givenY)
{
	y = givenY;
}


void Player::Initialize()
{
	//이미지 로드
	this->img = new GImage(Renderer(), "/ Resource / player.png");

	//좌표 초기화
	x = 100;
	y = 100;

}