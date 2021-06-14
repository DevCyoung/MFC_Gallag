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
			DefaultCreateMonster(i ,j);

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
// 몬스터를 생성한다.
// 몬스터를 생성하면서 
// 몬스터가 타일맵에서의 위치를 초기화한다.
Tile* MapManager::GetAlivePTile()
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
Monster* MapManager:: CreatePMonster()
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
void MapManager::FlyingCreateMonster(int i, int j, int startX, int startY)
{

	Monster* monster = CreatePMonster();
	Tile* tile = &tiles[i][j];

	tile->isAlive = true;

	monster->SetPosition(startX, startY);
	monster->SetTilePosition(tile->i, tile->j);

	monster->destinationX = tile->x;
	monster->destinationY = tile->y;

	int dirX = monster->destinationX - monster->x;
	int dirY = monster->destinationY - monster->y;

	float newRange = sqrt( pow(dirX, 2) + pow(dirY, 2) );

	monster->dir_x =  (dirX / newRange) * 14;
	monster->dir_y =  (dirY / newRange) * 14;

	monster->state = MOVE_FLY;



	//스타트 포인트

	return;



}
/// <summary>
/// i , j 번째 타일에 생성한다.
/// 이미 있으면 취소한다.
/// </summary>
void MapManager::DefaultCreateMonster(int i, int j)
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

void MapManager::CreateMonsterSize(int size)
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
				FlyingCreateMonster(i, j, startPos[index][0], startPos[index][1]);

				index++;
				if (index >= 3)
					index = 0;
			}

		}
	}


}



BEGIN_MESSAGE_MAP(MapManager, CWnd)
END_MESSAGE_MAP()



// MapManager 메시지 처리기


