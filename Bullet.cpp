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


BEGIN_MESSAGE_MAP(Bullet, CWnd)
END_MESSAGE_MAP()


