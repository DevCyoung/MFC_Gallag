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

	virtual void SetPosition(int x, int y);
	virtual void Show(CPaintDC& dc);
	virtual	void DirMoveTick();

	/// <summary>
	/// 현재 객체와 ch 객체를 비교해 충돌여부를 반환합니다.
	/// </summary>
	bool IsCollide(Charactor& ch);

	void DirSet(int _DirX, int _DirY, int _DirTick);
	



public:
	Charactor();
	virtual ~Charactor();

protected:
	DECLARE_MESSAGE_MAP()
};


