#pragma once

#include "cmath"

#define COLLIDE_SIZE 30

// Charactor
class Charactor : public CWnd
{
	DECLARE_DYNAMIC(Charactor);

public :
	CBitmap bitmap;
	BITMAP bmpinfo;

public:
	int ID_SPRITE = 0;
	int DirX;
	int DirY;
	int DirTick;

public :
	int x;
	int y;

	//default
	int CollideRange = COLLIDE_SIZE;

	bool isAlive = false;
	bool COLLIDE_VIEW = true;

public :
	const int X_SCREEN_SIZE = GetSystemMetrics(SM_CXSCREEN);
	const int Y_SCREEN_SIZE = GetSystemMetrics(SM_CYSCREEN);


public:

	/// <summary>
	/// 현재 객체와 ch 객체를 비교해 충돌여부를 반환합니다.
	/// </summary>
	bool IsCollide(Charactor &ch)
	{

		int newX = x - ch.x;
		int newY = y - ch.y;

		int newRange = sqrt( pow(newX, 2) + pow(newY, 2) );

		if (ch.CollideRange + CollideRange >= newRange)
			return true;
		return false;
		
	}



	virtual void Show(CPaintDC &dc)
	{


		if (isAlive == false)
			return;

		CDC memDC;
		CBrush brush;

		memDC.CreateCompatibleDC(&dc);
		memDC.SelectObject(&bitmap);

		/*dc.BitBlt(x - bmpinfo.bmWidth / 2 , y - bmpinfo.bmHeight / 2,
				  bmpinfo.bmWidth, bmpinfo.bmHeight,
			&memDC, 0, 0, SRCCOPY);*/

		::TransparentBlt(dc.m_hDC, x - bmpinfo.bmWidth / 2, y - bmpinfo.bmHeight / 2, bmpinfo.bmWidth, bmpinfo.bmHeight,
			memDC.m_hDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(255, 0, 255));

		if (COLLIDE_VIEW)
		{
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.Ellipse(x - CollideRange, y - CollideRange, x + CollideRange, y + CollideRange);

		}
		
	}

	virtual void SetPosition(int x , int y) 
	{
		this->x = x;
		this->y = y;

	}







	//___________수정 해야할 목록___________
	//
	//

	void DirSet(int _DirX, int _DirY, int _DirTick)
	{
		this->DirX = _DirX;
		this->DirY = _DirY;
		this->DirTick = _DirTick;
	}

    virtual	void DirMoveTick()
	{
		/*SetPosition(x, y - DirTick);*/
	}



public:
	Charactor();
	virtual ~Charactor();

protected:
	DECLARE_MESSAGE_MAP()
};


