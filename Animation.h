#pragma once


// Animation

class Animation : public CWnd
{
	DECLARE_DYNAMIC(Animation)

public:
	Animation();
	virtual ~Animation();


public :
	CBitmap bitmap[5];
	BITMAP bmpinfo[5];


protected:
	DECLARE_MESSAGE_MAP()
};


