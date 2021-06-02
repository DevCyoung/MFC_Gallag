// Monster.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Monster.h"
#include "time.h"

#define X_VAL 100;
#define Y_VAL 100;

#define MONSTER_SIZE 100;
#define MONSTER_DEFAULT_SPITE 313;

IMPLEMENT_DYNAMIC(Monster, CWnd)


int xPos = 0;
int yPos = 0;

int count = 0;

Monster::Monster()
{

	// srand( (unsigned int) (time(NULL) ) );
	// rand() % 4 => 0~ 3

	ID_SPRITE = 313 + count;

	bitmap.LoadBitmap(ID_SPRITE);
	bitmap.GetBitmap(&bmpinfo);
	isAlive = true;

	xPos += X_VAL;

	if (xPos % (1800) == 0)
	{
		yPos += Y_VAL;
		xPos  = X_VAL;
	}

	SetPosition(xPos, yPos + 200);

	count++;

	if (count >= 4) {
		count = 0;
	}

}

Monster::~Monster()
{
}


BEGIN_MESSAGE_MAP(Monster, CWnd)
END_MESSAGE_MAP()



// Monster 메시지 처리기


