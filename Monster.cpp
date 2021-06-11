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


BEGIN_MESSAGE_MAP(Monster, CWnd)
END_MESSAGE_MAP()



// Monster 메시지 처리기


