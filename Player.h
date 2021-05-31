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
		int newX = x;
		newX -= moveScale;

		if (0 > newX - 80)
			return;
		x -= moveScale;

	}
	void RightMove()
	{
		int newX = x;
		newX += moveScale;

		if (X_SIZE < newX + 80)
			return;
		x += moveScale;
	}

	void Shoot() 
	{
		bullets[bulletIndex].isShoot = true;
		bullets[bulletIndex].SetPosition(x, y - 20);
		bullets[bulletIndex].DirSet(0, 0, 10);
		bulletIndex++;

		if (bulletIndex >= BULLET_SIZE) {
			bulletIndex = 0;
		}

	}

	/*virtual void Show(CPaintDC& dc)
	{

		

			


	}*/
	

public :
	

protected:
	DECLARE_MESSAGE_MAP()
};


