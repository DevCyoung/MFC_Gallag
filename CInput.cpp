// CInput.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "CInput.h"


// CInput

IMPLEMENT_DYNAMIC(CInput, CWnd)

CInput::CInput()
{

}

CInput::~CInput()
{
}

void CInput :: Controller(Player& player, int tickCount)
{

	currentTick += tickCount;


	if (STATE & RIGHT)			//Right Move
	{
		player.RightMove();
	}
	else if (STATE & LEFT)		//LEFT Move
	{
		player.LeftMove();
	}

	if (STATE & SPACE)
	{

		if (currentTick > SHOOT_DELAY) {

			player.Shoot();
			currentTick = 0;

		}

	}
}


BEGIN_MESSAGE_MAP(CInput, CWnd)
END_MESSAGE_MAP()



// CInput 메시지 처리기


