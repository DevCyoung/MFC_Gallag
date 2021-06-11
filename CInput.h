#pragma once
#include "Player.h"
#include "Bullet.h"
// CInput

#define SHOOT_DELAY 10



class CInput : public CWnd
{
	DECLARE_DYNAMIC(CInput)

public:

	

	const int RIGHT = 0X00000001;
	const int LEFT  = 0X00000002;
	const int SPACE  = 0X00000004;

	int STATE = 0;


public :

	int currentTick = 100000;

	void Controller(Player& player, int tickCount);

	

public:
	CInput();
	virtual ~CInput();

protected:
	DECLARE_MESSAGE_MAP()
};


