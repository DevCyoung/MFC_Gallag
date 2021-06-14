#pragma once

#define Y_SIZE	4
#define X_SIZE	16
#define MONSTER_SIZE			64
#define MONSTER_PULL			300

#include "Monster.h"
#include "math.h"


// MapManager

struct Tile
{
	int x;
	int y;

	int i;
	int j;

	bool isAlive;

	void SetPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

};

class MapManager : public CWnd
{
	DECLARE_DYNAMIC(MapManager)

public:
	MapManager();
	virtual ~MapManager();

public:

	Tile tiles[Y_SIZE][X_SIZE] = {};
	Monster monsters[MONSTER_PULL] = {};

	int CurMonster = 0;
	int DieMonster = 0;

	int startPos[3][2] =
	{
		{1920 / 2 , -200 },
		{-200 , 540 },
		{2200 , 540 },

	};

	int index = 0;

public:
	/// <summary>
	/// 64마리의 몬스터를 소환한다.
	/// </summary>
	Monster* CreatePMonster();
	Tile* GetAlivePTile();

	void TilesInit();
	void DefaultCreateMonster(int i, int j);

	void FlyingCreateMonster(int i, int j, int startX, int startY);
	void CreateMonsterSize(int size);
	




protected:
	DECLARE_MESSAGE_MAP()
};


