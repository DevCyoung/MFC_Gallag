#pragma once


// Charactor

struct Vector2  
{

public:
	int x;
	int y;


public :
	void move() {

	}

};

class Charactor : public CWnd
{
	DECLARE_DYNAMIC(Charactor);


public :

	int x;
	int y;

	int DirX;
	int DirY;
	int DirTick;

	int ColiRange = 30;
	bool isColiide;
	bool isCollideView = true;

	CBitmap bitmap;
	BITMAP bmpinfo;

public :
	const int X_SIZE = GetSystemMetrics(SM_CXSCREEN);
	const int Y_SIZE = GetSystemMetrics(SM_CYSCREEN);
	

	

	
public:

	void IsCollide(Charactor &ch)
	{


		
	}

	virtual void Show(CPaintDC &dc)
	{
		CDC dcmem;
		CBrush brush;

		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		dc.BitBlt(x - bmpinfo.bmWidth / 2 , y - bmpinfo.bmHeight / 2, 
				  bmpinfo.bmWidth, bmpinfo.bmHeight,
			&dcmem, 0, 0, SRCCOPY);


		if (isCollideView) 
		{

			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.Ellipse(x - ColiRange , y - ColiRange , x + ColiRange , y + ColiRange);
			
		}

	}

	void SetPosition(int x , int y) 
	{
		this->x = x;
		this->y = y;

	}

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


