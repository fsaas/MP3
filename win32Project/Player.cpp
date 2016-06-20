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

float Player::getX()
{	
	return x;
}

float Player::getY()
{
	return y;
}

void Player::Initialize()
{
	//이미지 로드
	this->img = new GImage(Renderer(), "/ Resource / player.png");
	this->img = new GImage(Renderer(), "/ Resource / Action_Cart_Riding.bmp");

	//좌표 초기화
	x = 100;
	y = 148;
	speed = 1;
}

void Player::Destroy()
{

}

void Player::Update()
{
	walk();
	if (onGround())
	{
		jump();
	}
	if (IsKeyDown(VK_F2))
	{
		ride();
	}
}

void Player::Draw()
{
	if(isRide)
		Renderer()->Draw(img2, getX(), getY());
	else
		Renderer()->Draw(img, getX(), getY());
}

void Player::walk()
{
	if (IsKeyDown(VK_LEFT))
	{
		setX(getX() - speed);
	}
	if (IsKeyDown(VK_RIGHT))
	{
		setX(getX() + speed);
	}
}

void Player::jump()
{
	if (IsKeyDown(VK_UP))
	{
		while (getY() < 180 )
			setY(getY() + 3);
	}
}

bool Player::onGround()
{
	if (getX() < 149)
		return true;
	else
		return false;
}

bool Player::onCollision()
{
	return false;
}

void Player::ride()
{
	isRide = true;
	speed = 5;
}
