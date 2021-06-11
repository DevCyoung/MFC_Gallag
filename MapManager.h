#pragma once

#define MONSTER_VISIBLE_Y_SIZE	4
#define MONSTER_VISIBLE_X_SIZE	16
#define MONSTER_SIZE			64
#define MONSTER_PULL			300

#include "Monster.h"
#include "math.h"


// MapManager

struct Tile
{
	int x;
	int y;

	bool isShow;

	void SetPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void SetEmpty(bool value)
	{
		isShow = value;
	}
};

class MapManager : public CWnd
{
	DECLARE_DYNAMIC(MapManager)

public:
	MapManager();
	virtual ~MapManager();

public:

	Tile tiles[MONSTER_VISIBLE_Y_SIZE][MONSTER_VISIBLE_X_SIZE] = {};
	Monster monsters[MONSTER_PULL] = {};

	int CurMonster = 0;
	int DieMonster = 0;

public:
	/// <summary>
	/// 64마리의 몬스터를 소환한다.
	/// </summary>

	void TilesInitialzie()
	{

		static int m_xPos = 100;
		static int m_yPos = 0;

		for (int i = 0; i < MONSTER_VISIBLE_Y_SIZE; i++)
		{
			for (int j = 0; j < MONSTER_VISIBLE_X_SIZE; j++)
			{

				if (m_xPos % (1700) == 0)
				{
					m_yPos += 100;
					m_xPos = 100;
				}
				tiles[i][j].SetPosition(m_xPos, m_yPos + 200);
				m_xPos += 100;

			}
		}
	}



	// 몬스터를 생성한다.
	// 몬스터를 생성하면서 
	// 몬스터가 타일맵에서의 위치를 초기화한다.
	void FlyCreateMonster(int size)
	{

		for (int i = 0; i < MONSTER_VISIBLE_Y_SIZE; i++)
		{
			for (int j = 0; j < MONSTER_VISIBLE_X_SIZE; j++)
			{

				Tile* tile = &tiles[i][j];

				if (tile->isShow == false)
				{

					--size;

					DefaultCreateMonster(i, j);



				

				
				}

				if (size <= 0)
					return;

			}
		}

		

	}
	void DefaultCreateMonster(int i, int j)
	{

		static int pos = 0;
		if (pos >= MONSTER_PULL)
			pos = 0;

		monsters[pos].isAlive = true;
		monsters[pos].SetTilePosition(i, j);

		Tile* tile = &tiles[i][j];
		tile->isShow = true;
		monsters[pos].SetPosition(tile->x, tile->y);

		pos++;

		return;

	}

	int GetPos()
	{

		for (int i = 0; i < MONSTER_PULL; i++)
		{
			if (monsters[i].isAlive == false)
			{

			}

		}

	}

	void CreateMonsterSize(int size)
	{


		for (int i = 0; i < MONSTER_VISIBLE_Y_SIZE; i++)
		{
			for (int j = 0; j < MONSTER_VISIBLE_X_SIZE; j++)
			{

				if (size <= 0)
					return;

				//타일이 비어있다면
				if (tiles[i][j].isShow == false)
				{
					--size;
					Tile* tile = &tiles[i][j];
					DefaultCreateMonster(i , j);

				}


			}
		}
	}



protected:
	DECLARE_MESSAGE_MAP()
};


