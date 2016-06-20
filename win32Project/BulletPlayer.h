#pragma once
class GImage;

class BulletPlayer
{
private:
	GImage * m_playerImage;
	float m_xPos, m_yPos;
	float speed;

public:
	BulletPlayer();
	~BulletPlayer();

	void SetX();
	void SetY();
	float GetX();
	float GetY();

	void Initialize();
	void Update();
	void Draw();
	
	void Move();
	/**
	#1	->	플레이어의 이동 구현

	( 캐릭터를 화면에 생성한다 )
	( 키보드 키가 입력되었는지 확인 )
	( 입력받은 키의 방향으로 플레이어 이동 )
	
	*/

	void CreateBullet();
	/**
	#2	-> 탄환 발사

	( 캐릭터를 화면에 생성한다 ) 
	( 캐릭터의 좌표에 탄환을 생성한다 )
	( 생성된 탄환을 발사한다 )
	
	*/

	void CreateNWayBullet();
	/**
	#5	->	여러 방향으로 동시에 탄 발사하기
	
	( 캐릭터를 화면에 생성한다 )
	( 발사하는 탄 수가 여러개일 경우 설정된 각도에 따라 발사해야 하는 탄환 수만큼 탄환을 발사한다)

	*/

	void CollisionWithBullet();
	/**
	#9	->	충돌판정(탄막)

	( 캐릭터와 생성된 탄환이 각각 충돌범위를 갖는다 )
	( 캐릭터의 충돌범위와 탄환의 충돌범위가 겹친다 )
	( 플레이어가 HP는 감소한다 )
	( 탄막을 제거한다 )

	*/

	void CollisionWithEnemy();
	/**
	#10	->	충돌판정(적기와 플레이어)

	( 각 캐릭터는 개개별로 충돌범위를 갖는다 )
	( 캐릭터의 충돌범위와 적기의 충돌범위가 겹친다 )
	( 플레이어의 HP와 적기의 HP가 감소한다 )

	*/
};

