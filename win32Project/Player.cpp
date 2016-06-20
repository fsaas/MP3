#include "Player.h"
#include "mainProc.h"



Player::Player()
{
	isGround = false;
	isRide = false;
	isJump = false;
	//이미지 로드
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_Character.bmp");
	this->img2 = new GImage(Renderer(), "./Resource/Action_img/Action_Cart_Riding.bmp");

	//좌표 초기화
	x = 100;
	y = 640;
	speed = 10;

	//subFlag 생성
	subF = new subFlag();
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
}

void Player::Update()
{
	//깃발 위치에 있을 때
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
		
	//땅위에 있을 때
	if (onGround())
	{
		jump();
	}

	//점프할때
	if (isJump)
	{
		setY(getY() - 3);
		if (getY() < 580)
		{
			isJump = false;
		}
	}
	
	if (!isJump&&!isGround)
	{
		setY(getY() + 3);
		if (getY() > 620)
		{
			isJump = true;
		}
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
	if (getY() > 580 && IsKeyDown(VK_UP))
	{
		isJump = true;
	}
}

void Player::ride()
{
	isRide = true;
	speed = 5;
}

bool Player::onGround()
{
	if (getY() > 620)
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
	if (getX() > 800 && getX() < 820)
		return true;
	else
		return false;
}

void Player::down()
{
	while (getY()<640)
	{
		setY(getY() - 2);
	}
}

