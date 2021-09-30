#pragma once
#include "Charactor.h"


// Bullet

class Bullet : public Charactor
{
	// 이것이 코딩 테스트이다.

	DECLARE_DYNAMIC(Bullet)


public:
	Bullet();
	virtual ~Bullet();

public :
	virtual void DirMoveTick();

	


protected:
	DECLARE_MESSAGE_MAP()

};


