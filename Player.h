#pragma once

#include "Charactor.h"
#include "Bullet.h"
#include "MapManager.h"


// Player

class Player : public Charactor
{


	DECLARE_DYNAMIC(Player)



public:
	Player();
	virtual ~Player();

public :

	int moveScale = 15;

	Bullet bullets[BULLET_PULL];

	int bulletIndex = 0;


public :

	void LeftMove();
	void RightMove();
	void Shoot();


public :
	

protected:
	DECLARE_MESSAGE_MAP()
};


