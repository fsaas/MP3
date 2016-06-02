#pragma once
class Player
{
private:


public:
	Player();
	~Player();

	void walk();				  //1
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

