#pragma once


// Animation

static int pos = 0;

class Animation : public CWnd
{
	DECLARE_DYNAMIC(Animation)

public:
	Animation();
	virtual ~Animation();




public :

	CBitmap bitmaps[5];
	BITMAP bmpinfos[5];

	int index = 0;

	int boomTickCount = 0;
	int boomIndex = 0;

	bool isShow = false;

	int x = -100;
	int y = -100;
	
	

	void Show(CPaintDC &dc)
	{

		if (isShow == false)
			return;

		++boomTickCount;
		if (boomTickCount > 2)
		{
			++boomIndex;
			boomTickCount = 0;
		}

		if (boomIndex >= 5)
		{
			Init();
		}


		CDC memDC;
		CBitmap* my_bit = &bitmaps[boomIndex];

		memDC.CreateCompatibleDC(&dc);
		memDC.SelectObject(my_bit);

		BITMAP tickInfo;
		my_bit->GetBitmap(&tickInfo);

		//배경 투명화 하면서 그린다.
		::TransparentBlt(dc.m_hDC, x - tickInfo.bmWidth / 2, y - tickInfo.bmHeight / 2, tickInfo.bmWidth, tickInfo.bmHeight,
			memDC.m_hDC, 0, 0, tickInfo.bmWidth, tickInfo.bmHeight, RGB(255, 0, 255));

	}

	void Init()
	{
		isShow = false;
		boomTickCount = 0;
		boomIndex = 0;
		x = -100;
		y = -100;
	}

	void SetPosition(int x, int y)
	{
		this->x = x;
		this->y = y;

	}

	

	

protected:
	DECLARE_MESSAGE_MAP()
};


