#pragma once
#include "Charactor.h"


// Bullet

class Bullet : public Charactor
{

	DECLARE_DYNAMIC(Bullet)


public:
	Bullet();
	virtual ~Bullet();

public :
	virtual void DirMoveTick();

	


protected:
	DECLARE_MESSAGE_MAP()

};


