// Player.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Player.h"


// Player

IMPLEMENT_DYNAMIC(Player, CWnd)

Player::Player()
{

	bitmap.LoadBitmap(IDB_CRAFT);
	bitmap.GetBitmap(&bmpinfo);


}

Player::~Player()
{
}


BEGIN_MESSAGE_MAP(Player, CWnd)
END_MESSAGE_MAP()



// Player 메시지 처리기


