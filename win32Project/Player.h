#pragma once
class Player
{
private:


public:
	Player();
	~Player();

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

	
	(1)	한 쪽 방향(위 또는 아래)으로 움직이는 플랫폼에 대하여, 캐릭터가 플랫폼 위에 위치한 경우
	
	(2)	캐릭터는 플랫폼이 움직이는 속력과 같은 속력으로 위 / 아래로 이동함.
	
	
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
	void useItem();				  //8	아이템 사용
	void ladder();				  //9	사다리 타기
	void getScore();			  //10	점수 변환



};

