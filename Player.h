#pragma once

#include "Charactor.h"
#include "Bullet.h"

#define BULLET_SIZE 100

// Player

class Player : public Charactor
{


	DECLARE_DYNAMIC(Player)



public:
	Player();
	virtual ~Player();

public :

	int moveScale = 15;

	Bullet bullets[BULLET_SIZE];

	int bulletIndex = 0;


public :

	void LeftMove();
	void RightMove();
	void Shoot();


public :
	

protected:
	DECLARE_MESSAGE_MAP()
};


