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

	
	virtual void DirMoveTick()
	{

		if (isAlive == false)
			return;

		SetPosition(x, y - DirTick);

		if (y < -30) 
		{
			isAlive = false;
		}
	}


protected:
	DECLARE_MESSAGE_MAP()

};


