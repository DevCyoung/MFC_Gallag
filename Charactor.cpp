	// Charactor.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Charactor.h"


// Charactor

IMPLEMENT_DYNAMIC(Charactor, CWnd)



Charactor::Charactor()
{



}

Charactor::~Charactor()
{
}

bool Charactor :: IsCollide(Charactor& ch)
{

	int newX = x - ch.x;
	int newY = y - ch.y;

	int newRange = sqrt(pow(newX, 2) + pow(newY, 2));

	if (ch.CollideRange + CollideRange >= newRange)
		return true;
	return false;

}



void Charactor ::  Show(CPaintDC& dc)
{


	if (isAlive == false )
		return;

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);

	//배경 투명화 하면서 그린다.
	::TransparentBlt(dc.m_hDC, x - bmpinfo.bmWidth / 2, y - bmpinfo.bmHeight / 2, bmpinfo.bmWidth, bmpinfo.bmHeight,
		memDC.m_hDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(255, 0, 255));


	if (ch_state == LIVE)
	{


	}
	else if (ch_state == BOOM)
	{

		//++anim.boomTickCount;
		//if (anim.boomTickCount > 4)
		//{
		//	++anim.boomIndex;
		//	anim.boomTickCount = 0;
		//}

		//if (anim.boomIndex >= 5)
		//{

		//	anim.boomIndex = 4;
		//	ch_state = DIE;

		//}
		//	

		//CDC memDC;
		//CBitmap *my_bit = &anim.bitmaps[anim.boomIndex];
		//memDC.CreateCompatibleDC(&dc);
		//memDC.SelectObject(my_bit);
		//BITMAP tickInfo;
		//my_bit->GetBitmap(&tickInfo);

		////배경 투명화 하면서 그린다.
		//::TransparentBlt(dc.m_hDC, x - tickInfo.bmWidth / 2, y - tickInfo.bmHeight / 2, tickInfo.bmWidth, tickInfo.bmHeight,
		//	memDC.m_hDC, 0, 0, tickInfo.bmWidth, tickInfo.bmHeight, RGB(255, 0, 255));


	}





	if (COLLIDE_VIEW)
	{
		CBrush brush;
		brush.CreateStockObject(NULL_BRUSH);
		dc.SelectObject(&brush);
		dc.Ellipse(x - CollideRange, y - CollideRange, x + CollideRange, y + CollideRange);
	}




}
void Charactor :: SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;

}

//___________수정 해야할 목록___________
void Charactor::DirSet(int _DirX, int _DirY, int _DirTick)
{
	this->DirX = _DirX;
	this->DirY = _DirY;
	this->DirTick = _DirTick;
}
void Charactor:: DirMoveTick()
{
	
}

BEGIN_MESSAGE_MAP(Charactor, CWnd)
END_MESSAGE_MAP()



// Charactor 메시지 처리기


