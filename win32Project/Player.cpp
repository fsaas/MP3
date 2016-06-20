#include "Player.h"
#include "mainProc.h"



Player::Player()
{
	stageNum = 1;
	isGround = false;
	isRide = false;
	isJump = false;
	//�̹��� �ε�
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_Character.bmp");
	this->img2 = new GImage(Renderer(), "./Resource/Action_img/Action_Cart_Riding.bmp");

	//��ǥ �ʱ�ȭ
	x = 100;
	y = 640;
	speed = 3;

}

Player::Player(int given)
{
	stageNum = given;

	isGround = false;
	isRide = false;
	isJump = false;
	//�̹��� �ε�
	this->img = new GImage(Renderer(), "./Resource/Action_img/Action_Character.bmp");
	this->img2 = new GImage(Renderer(), "./Resource/Action_img/Action_Cart_Riding.bmp");

	//��ǥ �ʱ�ȭ
	x = 100;
	y = 640;
	speed = 3;

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
	//��� ��ġ�� ���� ��
	if (onFlag() && stageNum == 9)
	{

	}
	else
	{
		walk();
	}
		
	//������ ���� ��
	if (onGround())
	{
		jump();
	}

	//�����Ҷ�
	if (isJump)
	{
		setY(getY() - 3);
		if (getY() < 580)
		{
			isJump = false;
			isGround = false;
		}
	}
	else
	{
		if (!isGround)
		{
			setY(getY() + 3);
			if (getY() > 640)
			{
				isGround = true;
			}
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
	speed = 10;
}

bool Player::onGround()
{
	if (getY() > 640)
	{
		isGround = true;
		return true;
	}
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
		setY(getY() + 1);
	}
}

