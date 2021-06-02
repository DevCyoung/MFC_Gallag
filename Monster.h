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






protected:
	DECLARE_MESSAGE_MAP()
};


