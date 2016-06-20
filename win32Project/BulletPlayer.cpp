#include "BulletPlayer.h"
#include "mainProc.h"
#include "GWindow.h"

BulletPlayer::BulletPlayer()
{

}

BulletPlayer::~BulletPlayer()
{

}

void BulletPlayer::Initialize() {

}

void BulletPlayer::Update() {

}

void BulletPlayer::Draw() {

}

void BulletPlayer::SetX(float x) {
	this->m_xPos = x;
}

void BulletPlayer::SetY(float y) {
	this->m_yPos = y;
}

float BulletPlayer::GetX() {
	return m_xPos;
}

float BulletPlayer::GetY() {
	return m_yPos;
}

/**
#1	->	플레이어의 이동 구현

( 캐릭터를 화면에 생성한다 )
( 키보드 키가 입력되었는지 확인 )
( 입력받은 키의 방향으로 플레이어 이동 )

*/
void BulletPlayer::Move() {
	if (IsKeyDown(VK_LEFT)) {
		this->SetX(GetX() - this->speed);
	}
	if (IsKeyDown(VK_RIGHT)) {
		this->SetX(GetX() + this->speed);
	}
	if (IsKeyDown(VK_UP)) {
		this->SetY(GetY() - this->speed);
	}
	if (IsKeyDown(VK_DOWN)) {
		this->SetY(GetY() + this->speed);
	}
}

/**
#2	-> 탄환 발사

( 캐릭터를 화면에 생성한다 )
( 캐릭터의 좌표에 탄환을 생성한다 )
( 생성된 탄환을 발사한다 )

*/
void BulletPlayer::CreateBullet() {

}

/**
#5	->	여러 방향으로 동시에 탄 발사하기

( 캐릭터를 화면에 생성한다 )
( 발사하는 탄 수가 여러개일 경우 설정된 각도에 따라 발사해야 하는 탄환 수만큼 탄환을 발사한다)

*/
void BulletPlayer::CreateNWayBullet() {

}

/**
#9	->	충돌판정(탄막)

( 캐릭터와 생성된 탄환이 각각 충돌범위를 갖는다 )
( 캐릭터의 충돌범위와 탄환의 충돌범위가 겹친다 )
( 플레이어가 HP는 감소한다 )
( 탄막을 제거한다 )

*/
void BulletPlayer::CollisionWithBullet() {

}

/**
#10	->	충돌판정(적기와 플레이어)

( 각 캐릭터는 개개별로 충돌범위를 갖는다 )
( 캐릭터의 충돌범위와 적기의 충돌범위가 겹친다 )
( 플레이어의 HP와 적기의 HP가 감소한다 )

*/
void BulletPlayer::CollisionWithEnemy() {

}
