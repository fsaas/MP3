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
	this->img = new GImage(Renderer(), "./ Resource / player.png");
	this->img = new GImage(Renderer(), "./ Resource / Action_Cart_Riding.bmp");

	//좌표 초기화
	x = 100;
	y = 148;
	speed = 1;

	//subFlag 생성
	subF = new subFlag();
}

void Player::Update()
{

	if (onFlag())
	{
		score = getY();
		down();
		subF->down();
	}
	else
	{
		walk();
	}
		
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


void Player::ride()
{
	isRide = true;
	speed = 5;
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

bool Player::onFlag()
{
	if (getX() > 800 || getX() < 820)
		return true;
	else
		return false;
}

void Player::down()
{
	while (getY()>129)
	{
		setY(getY() - 2);
	}
}

