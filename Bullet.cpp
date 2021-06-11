// Bullet.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Bullet.h"


// Bullet

IMPLEMENT_DYNAMIC(Bullet, CWnd)

Bullet::Bullet()
{


	bitmap.LoadBitmap(IDB_BULLET);
	bitmap.GetBitmap(&bmpinfo);
	CollideRange = 16;
	DirTick = 50;

}

Bullet::~Bullet()
{


}



void Bullet :: DirMoveTick()
{

	if (isAlive == false)
		return;

	SetPosition(x, y - DirTick);

	if (y < -30)
	{
		isAlive = false;
	}

}

BEGIN_MESSAGE_MAP(Bullet, CWnd)
END_MESSAGE_MAP()


