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

	void LeftMove() 
	{
		int tempX = x;
		tempX -= moveScale;

		if (0 > tempX - 80)
			return;
		x -= moveScale;

	}

	void RightMove()
	{
		int tempX = x;
		tempX += moveScale;

		if (X_SCREEN_SIZE < tempX + 80)
			return;
		x += moveScale;
	}	

	void Shoot() 
	{

		/*bullets[bulletIndex].DirSet(0, 0, 50);*/

		bullets[bulletIndex].isAlive = true;
		bullets[bulletIndex].SetPosition(x, y - 20);
		bulletIndex++;

		if (bulletIndex >= BULLET_SIZE) {
			bulletIndex = 0;
		}

	}

public :
	

protected:
	DECLARE_MESSAGE_MAP()
};


