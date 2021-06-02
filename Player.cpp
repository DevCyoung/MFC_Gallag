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


BEGIN_MESSAGE_MAP(Player, CWnd)
END_MESSAGE_MAP()



// Player 메시지 처리기


