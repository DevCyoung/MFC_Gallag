// MapManager.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "MapManager.h"


// MapManager

IMPLEMENT_DYNAMIC(MapManager, CWnd)

MapManager::MapManager()
{

	
	TilesInit();


	for (int i = 0; i < Y_SIZE; i++)
	{
		for(int j = 0; j < X_SIZE; j++)
		{

			Tile* tile = &tiles[i][j];
			SetDefaultMonster(i ,j);

		}
	}

}
MapManager::~MapManager()
{
}

void MapManager::TilesInit()
{
	static int m_xPos = 100;
	static int m_yPos = 0;

	for (int i = 0; i < Y_SIZE; i++)
	{
		for (int j = 0; j < X_SIZE; j++)
		{

			if (m_xPos % (1700) == 0)
			{
				m_yPos += 100;
				m_xPos = 100;
			}
			tiles[i][j].SetPosition(m_xPos, m_yPos + 200);
			tiles[i][j].i = i;
			tiles[i][j].j = j;
			m_xPos += 100;

		}
	}


	for (int i = 0; i < MONSTER_PULL; i++)
	{
		monsters[i].isAlive = false;
	}
}

Tile* MapManager::GetAliveTile()
{


	for (int i = 0; i < Y_SIZE; i++)
	{
		for (int j = 0; j < X_SIZE; j++)
		{

			if (tiles[i][j].isAlive == false)
			{
				tiles[i][j].isAlive = true;
				return &tiles[i][j];

			}

		}
	}

}

Monster* MapManager:: GetDieMonster()
{

	for (int i = 0; i < MONSTER_PULL; i++)
	{

		if ( monsters[i].isAlive == false )
		{
			monsters[i].isAlive = true;
			return &monsters[i];
		}

	}

}
Monster* MapManager::GetLiveIDLEMonster()
{
	for (int i = 0; i < MONSTER_PULL; i++)
	{

		if (monsters[i].isAlive == true && monsters[i].state == MOVE_IDLE)
		{
			return &monsters[i];
		}

	}
}
void MapManager::SetDefaultMonster(int i, int j)
{

	static int pos = 0;
	if (pos >= MONSTER_PULL)
		pos = 0;

	monsters[pos].isAlive = true;
	monsters[pos].SetTilePosition(i, j);

	Tile* tile = &tiles[i][j];
	tile->isAlive = true;
	monsters[pos].SetPosition(tile->x, tile->y);

	pos++;

	return;

}
void MapManager::SetMonster(int i, int j, int startX, int startY)
{


	Monster* monster = GetDieMonster();
	Tile* tile = &tiles[i][j];

	tile->isAlive = true;

	monster->SetPosition(startX, startY);
	monster->SetTilePosition(tile->i, tile->j);

	monster->destinationX = tile->x;
	monster->destinationY = tile->y;

	float dirX = monster->destinationX - monster->x;
	float dirY = monster->destinationY - monster->y;

	float newRange = sqrt(dirX * dirX + dirY* dirY );

	monster->dir_x =  dirX / newRange;
	monster->dir_y =  dirY / newRange;

	monster->state = MOVE_FLY;

	return;



}
void MapManager::CreateMonster(int size)
{


	// ver 01

	for (int i = 0; i < Y_SIZE; i++)
	{
		for (int j = 0; j < X_SIZE; j++)
		{

			if (size <= 0)
				return;

			if (tiles[i][j].isAlive == false)
			{
				--size;
				SetMonster(i, j, startPos[index][0], startPos[index][1]);

				index++;
				if (index >= 6)
					index = 0;
			}

		}
	}


}

//void MapManager::Attack(int size , Player &player)
//{
//
//
//	for (int i = 0; i < size; i++)
//	{
//
//		Monster* pMonster = GetLiveIDLEMonster();
//
//		
//		Tile* tile = &tiles[pMonster->i][pMonster->j];
//
//		tile->isAlive = true;
//
//		pMonster->destinationX = player.x;
//		pMonster->destinationY = player.y;
//
//		float dirX = pMonster->destinationX - pMonster->x;
//		float dirY = pMonster->destinationY - pMonster->y;
//
//		float newRange = sqrt(dirX * dirX + dirY * dirY);
//
//		pMonster->dir_x = dirX / newRange;
//		pMonster->dir_y = dirY / newRange;
//
//		pMonster->state = MOVE_ATTACK;
//
//
//
//	}
//
//
//}


BEGIN_MESSAGE_MAP(MapManager, CWnd)
END_MESSAGE_MAP()



// MapManager 메시지 처리기


