#pragma once
#include "GRenderer.h"
#include "GImage.h"
class Player
{
private:
	GImage *img;
	GImage *img2;
	bool isGround;
	bool isRide;
	float x;
	float y;
	float speed;
public:
	Player();
	~Player();
	void setX(float);
	void setY(float);
	float getX();
	float getY();
	void Initialize();
	void Destroy();
	void Update();
	void Draw();
	void walk();				  
	/*					#1
	( 정답 ) [ 오답 ]

	( 캐릭터의 아래가 땅인지 확인 )
	( 키보드의 키가 눌러졌는지 확인 )
	( 캐릭터의 위치를 움직임 1 )
	( 캐릭터 의 방향을 변경 )
	
	[ 캐릭터의 아래에 아무것도 없는지 확인 ] - 캐릭터의 아래에 무엇이라도 존재한다면 정상적으로 이동함  
	[ 키보드의 키가 눌린 후 떼어졌는지 확인 ]	- 키보드의 방향키가 한번이라도 눌리면 해당방향으로 이동함
	[ 캐릭터 이미지의 위치를 움직임 ] - 캐릭터 오브젝트가 아닌 캐릭터의 이미지가 이동하여 정상적으로 진행되지 않음
	[ 캐릭터 움직이는 방향을 변경 ] - 캐릭터가 키가 눌린 방향과 반대방향으로 이동하게됨.
	*/
	void jump();			
	/*					#2
	
	( 키보드의 점프 키가 눌러졌는지 확인 1 ) - 점프 중에 점프 불가능
	( 캐릭터의 위치를 움직임 2 )  - 캐릭터를 상하로 움직임
	( 캐릭터의 위에 블럭이 있는지 확인 )
	( 아래 버튼을 누른 후 점프 키가 눌러졌는지 확인 ) - 아래로 이동할수 있는경우 아래로 점프 함

	[ 키보드의 점프 키가 눌러졌는지 확인 2 ] - 점프 키를 떼면 상승을 중지함.
	[ 캐릭터의 이미지의 위치를 움직임 ] - 캐릭터의 이미지만 점프하는 형태를 보여줌.
	[ 캐릭터의 아래에 블럭이 있는지 확인 ]
	[ 아래 버튼이 눌러졌는지 확인 ] - 아래 키를 누르면 현재 서 있는 플랫폼 아래로 이동함
	
	*/
	void platform_LeftandRight(); 		  

	/*					#3
	
	( 움직이는 플랫폼 위에 캐릭터가 존재하는지 확인 ) 
	( 캐릭터의 상태를 변경 1 ) - 플랫폼 위에 위치한 모든 캐릭터의 상태를 '플랫폼 위에 위치한 상태' 로 변경함
	( 캐릭터의 위치를 조금씩 변화시킴 )
	( 캐릭터가 움직이는 방향이 플랫폼이 기능하는방향과 같다면 캐릭터의 움직이는 속도에+,반대 방향이라면 - 를 적용 )

	
	[ 캐릭터의 상태를 변경 2 ] - 플랫폼 위에 위치한 플레이어 캐릭터의 상태를 '플랫폼 위에 위치한 상태' 로 변경
	[ 캐릭터의 기본 속력을 변화시킴 ] - 캐릭터가 움직이는 기본 속도를 변화시켜, 플랫폼위를 벗어나더라도 이동속도가 증가한 상태로 유지됨 
	[ 캐릭터의 기본 위치를 변화시킴 ] - 캐릭터가 플랫폼위를 벗어나더라도 플랫폼 위에 한번이라도 올라갔다면 계속 움직이게됨
	
	
	*/
	void platform_UpandDown();	  	  //4

	/*

    (위/아래 쪽으로 지속적으로 움직이는 플랫폼 위에 캐릭터가 있는지 확인)
	(캐릭터의 위치를 플랫폼의 위치에 더해지도록 설정)

	
	[캐릭터의 위치를 기본 위치에서 변하도록 설정] - 플랫폼에서 이탈한 경우에도 해당위치에 고정됨

	
	*/
	void ride();				  //5
	/*
	
	( 타기/내리기 버튼이 눌러졌는지 확인 )
		(캐릭터 속성변경 1) - 캐릭터의 속성을 일반->탑승 한 캐릭터 로 변경시킨다.
		(탑승물 제거) -  캐릭터 주변의 탑승물 제거

		(캐릭터 속성변경 2) - 캐릭터의 속성을 탑승 한 캐릭터->일반 으로 변경시킨다.
		(탑승물 생성) -  캐릭터 주변에 탑승물 생성

		[속성변경 하지않음] - 캐릭터의 속성을 변경하지 않음.

	[ 타기/내리기 버튼이 눌러졌는지 확인하지 않음 

	*/

	void jumpAttck();			  //6	점프 밟기 공격
	void takeItem();			  //7	아이템 획득
	void useItem();				  //8	아이템 사용 ( 무기 사용 )
	/*
	
	( 아이템을 획득했는지 확인 ) - 캐릭터가 현재 무기 아이템을 소유하고 있는지 확인함
	( 아이템 사용 키를 눌렀는지 확인 ) - 아이템 사용 키가 눌러졌는지 확인한다.
	( 미사일이 생성됨 ) - 아이템이 사용되어 미사일이 나간다.
	( 미사일에 맞은 유닛이 삭제됨 ) - 미사일과의 거리가 일정 수준 이하일 경우, 피격됬다고 인식하고 피격체를 제거함
	
	
	[ 캐릭터 주변에 아이템이 있는지 확인 ] - 캐릭터가 아이템과 일정 거리 내에 있을 경우에만 아이템 사용 가능.
	[ 아이템 사용 키가 눌렸는지 확인하지 않음 ] - 아이템 사용 키가 눌러지지 않더라도 아이템이 계속 사용된다.
	[ 미사일이 제거됨 ] - 미사일 과의 거리가 일정 수준 이하인 경우, 미사일이 제거된다 
	                     //적 유닛 주변에 미사일이 닿기 이전에 사라지므로 유닛은 절대 제거되지 않음.
	[ 아이템이 사라짐 ] - 캐릭터가 소유하고 있던 아이템을 제거함. 
	
	
	*/
	void ladder();				  //9	사다리 타기
	void getScore();			  //10	점수 변환

	/*
	
	( 캐릭터 위치 확인 ) - 캐릭터가 깃대 뒤로 넘어갔는지 확인한다.
	( 캐릭터 위치 변화 제한 ) - 캐릭터가 키보드의 입력에 의해 움직이지 않도록 변경한다.
	( 하강 애니메이션 ) - 깃발과 캐릭터가 함께 수직하강하는 애니메이션 효과
	( 점수 변환 ) - 캐릭터가 깃발에 도착했을때의 높이(y 좌표상의 거리)의 일정 비율을 점수로 환산함
	

	[ 깃대에 도착 ] - 깃대 주변 일정거리 이내에 캐릭터가 있는지 확인
	[ 깃발 제거 ] - 깃발 이미지를 제거한다
	[ 키보드 입력 제한 ] - 캐릭터를 조종하는 키보드의 입력을 중지시킨다.
	[ 키보드 입력 재개 ] - 캐릭터를 조종하는 키보드의 입력을 작동시킨다.
	

	
	*/

	bool onGround();
	bool onCollision();
};

