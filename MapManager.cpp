// MapManager.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "MapManager.h"


// MapManager

IMPLEMENT_DYNAMIC(MapManager, CWnd)

MapManager::MapManager()
{

	
	TilesInitialzie();


	for (int i = 0; i < MONSTER_VISIBLE_Y_SIZE; i++)
	{
		for(int j = 0; j < MONSTER_VISIBLE_X_SIZE; j++)
		{

			Tile* tile = &tiles[i][j];
			DefaultCreateMonster(i ,j);

		}
	}

}

MapManager::~MapManager()
{
}


BEGIN_MESSAGE_MAP(MapManager, CWnd)
END_MESSAGE_MAP()



// MapManager 메시지 처리기


