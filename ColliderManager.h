#pragma once


// ColliderManager

#include "Player.h"
#include "Monster.h"

class ColliderManager : public CWnd
{
	DECLARE_DYNAMIC(ColliderManager)

public:
	ColliderManager();
	ColliderManager(Player player, Monster monster);
	virtual ~ColliderManager();

public :





protected:
	DECLARE_MESSAGE_MAP()
};


