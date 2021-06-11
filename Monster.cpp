// Monster.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Monster.h"
#include "time.h"

#define X_VAL 100;
#define Y_VAL 100;

IMPLEMENT_DYNAMIC(Monster, CWnd)


int xPos = 100;
int yPos = 0;

int count = 0;

Monster::Monster()
{
	//초기화
	//SET SPRITE

	ID_SPRITE = 313 + count;
	isAlive = true;

	count++;

	if (count >= 4) {
		count = 0;
	}

	//LOAD BITMAP
	bitmap.LoadBitmap(ID_SPRITE);
	bitmap.GetBitmap(&bmpinfo);



}

Monster::~Monster()
{
}


void Monster:: DirMoveTick()
{
	tickCount += 1;

	if (state == MOVE_IDLE)
	{
		if (tickCount < 40)
			return;
		SetPosition(x + 20 * dir, y);
		dir *= -1;
		tickCount = 0;


	}
	else if (state == MOVE_FLY)
	{

		SetPosition(x + dir_x, y + dir_y);

		int newX = destinationX - x;
		int newY = destinationY - y;

		if (newX < 0)
			newX *= -1;

		if (newY < 0)
			newY *= -1;

		if (newX < 50 && newY < 50)
		{
			SetPosition(destinationX, destinationY);
			state = MOVE_IDLE;
			tickCount = 0;
		}


	}
	else if (state == MOVE_ATTACK)
	{
		SetPosition(x + dir_x, y + dir_y);
	}



}


BEGIN_MESSAGE_MAP(Monster, CWnd)
END_MESSAGE_MAP()



// Monster 메시지 처리기


