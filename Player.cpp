// Player.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Player.h"


// Player

IMPLEMENT_DYNAMIC(Player, CWnd)


Player::Player()
{

	int ID_SPRITE = IDB_CRAFT;
	bitmap.LoadBitmap(ID_SPRITE);
	bitmap.GetBitmap(&bmpinfo);
	isAlive = true;
	SetPosition( X_SCREEN_SIZE / 2 , Y_SCREEN_SIZE - bmpinfo.bmHeight - 50);

}
Player::~Player()
{
}
void Player::LeftMove()
{
	int tempX = x;
	tempX -= moveScale;

	if (0 > tempX - 80)
		return;
	x -= moveScale;

}
void Player::RightMove()
{
	int tempX = x;
	tempX += moveScale;

	if (X_SCREEN_SIZE < tempX + 80)
		return;
	x += moveScale;
}
void Player::Shoot()
{


	/*bullets[bulletIndex].isAlive = true;
	bullets[bulletIndex].SetPosition(x, y - 20);
	bulletIndex++;

	if (bulletIndex >= BULLET_PULL) {
		bulletIndex = 0;
	}*/

	// Double S

	

	int test[6][5] =
	{
		{0},
		{0},
		{-25,25},
		{-35,0, 35},
		{-40,-15,15,40},
		{-50,-25,0,25,50}
	};


	for (int i = 0; i < curPower; i++)
	{
		bullets[bulletIndex].isAlive = true;
		bullets[bulletIndex].SetPosition(x + test[curPower][i] , y - 20);

		bulletIndex++;

		if (bulletIndex >= BULLET_PULL) {
			bulletIndex = 0;
		}

	}




}

BEGIN_MESSAGE_MAP(Player, CWnd)
END_MESSAGE_MAP()



// Player 메시지 처리기


