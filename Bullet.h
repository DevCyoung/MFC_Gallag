#pragma once
#include "Charactor.h"


// Bullet

class Bullet : public Charactor
{

	DECLARE_DYNAMIC(Bullet)


public:
	Bullet();
	virtual ~Bullet();

public :
	bool isShoot = false;

	virtual void DirMoveTick()
	{

		SetPosition(x, y - DirTick);

		if (y < -30) 
		{
			isShoot = false;

		}


	}


protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


