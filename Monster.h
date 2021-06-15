#pragma once

#include "Charactor.h"

// Monster

enum MON_STATE
{
	MOVE_FLY,
	MOVE_IDLE,
	MOVE_ATTACK,

};

class Monster : public Charactor
{
	DECLARE_DYNAMIC(Monster)

public:
	Monster();
	virtual ~Monster();

	
	int dir = -1;

	//Tile I , J
	int i;
	int j;

	//����
	MON_STATE state = MOVE_IDLE;

	//���⺤��
	float dir_x;
	float dir_y;

	//������
	float destinationX;
	float destinationY;

	int tickCount = 100;

	virtual void DirMoveTick();
	void Attack();

	
		

	inline void SetTilePosition(int i, int j)
	{
		this->i = i;
		this->j = j;
	}

	void MonsterInitialize()
	{

		SetPosition(0, 0);

	}


protected:
	DECLARE_MESSAGE_MAP()
};


