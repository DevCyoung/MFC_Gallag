#pragma once

#include "Charactor.h"

// Monster

class Monster : public Charactor
{
	DECLARE_DYNAMIC(Monster)

public:
	Monster();
	virtual ~Monster();

	//virtual void Show(CPaintDC& dc )
	//{

	//	Charactor::Show(dc);

	//}

	int tickCount = 100;
	int dir = -1;

	// 수정해야함
	virtual void DirMoveTick()
	{
		tickCount += 1;
		if (tickCount > 40 && dir == -1) {
			SetPosition(x - 20, y);
			tickCount = 0;
			dir = 1;
		}
		else if (tickCount > 40 && dir == 1)
		{
			SetPosition(x + 20, y);
			tickCount = 0;
			dir = -1;
		}
	}

protected:
	DECLARE_MESSAGE_MAP()
};


