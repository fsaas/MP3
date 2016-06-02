#pragma once
class Player
{
private:


public:
	Player();
	~Player();

	void walk();				  //1
	/*
	( 정답 ) [ 오답 ]

	( 캐릭터의 아래가 땅인지 확인 ) ( 키보드의 키가 눌러졌는지 확인 ) ( 캐릭터의 위치를 움직임 ) ( 캐릭터 의 방향을 변경 )
	[ 캐릭터의 아래에 아무것도 없는지 확인 ] - 캐릭터의 아래에 무엇이라도 존재한다면 정상적으로 이동함  
	[ 키보드의 키가 눌린 후 떼어졌는지 확인 ]	- 키보드의 방향키가 한번이라도 눌리면 해당방향으로 이동함
	[ 캐릭터 이미지의 위치를 움직임 ] - 캐릭터 오브젝트가 아닌 캐릭터의 이미지가 이동하여 정상적으로 진행되지 않음
	[ 캐릭터 움직이는 방향을 변경 ] - 캐릭터가 키가 눌린 방향과 반대방향으로 이동하게됨.




	*/
	void jump();				  //2
	void platform_LeftandRight(); 		  //3
	void platform_UpandDown();	  	  //4
	void ride();				  //5
	void jumpAttck();			  //6	점프 밟기 공격
	void takeItem();			  //7	아이템 획득
	void useItem();				  //8	아이템 사용
	void ladder();				  //9	사다리 타기
	void getScore();			  //10	점수 변환



};

