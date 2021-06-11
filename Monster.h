#pragma once

#include "Charactor.h"

// Monster

enum MON_STATE
{
	MOVE_FLY,
	MOVE_IDLE,


};

class Monster : public Charactor
{
	DECLARE_DYNAMIC(Monster)

public:
	Monster();
	virtual ~Monster();

	
	int dir = -1;

	//Dir I , J
	int i;
	int j;

	//상태
	MON_STATE state = MOVE_IDLE;

	//방향벡터
	int dir_x;
	int dir_y;

	//목적지
	int destinationX;
	int destinationY;

	int tickCount = 100;

	virtual void DirMoveTick()
	{
		tickCount += 1;

		if (state == MOVE_IDLE)
		{
			if (tickCount < 40)
				return;
			SetPosition(x + 20 * dir, y);
			dir *= -1;
			tickCount = 0;
		}
		else if (state == MOVE_FLY)
		{
			
			SetPosition(x + dir_x, y + dir_y);

			int newX = destinationX - x;
			int newY = destinationY - y;

			if (newX < 0)
				newX *= -1;

			if (newY < 0)
				newY *= -1;

			if (newX < 5 && newY < 5)
			{
				SetPosition(destinationX, destinationY);
				state = MOVE_IDLE;
			}


		}

		

	}

	inline void SetTilePosition(int i, int j) 
	{
		this->i = i;
		this->j = j;
	}




protected:
	DECLARE_MESSAGE_MAP()
};


