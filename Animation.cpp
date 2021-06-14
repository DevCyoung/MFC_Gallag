// Animation.cpp: 구현 파일
//

#include "pch.h"
#include "Gallag.h"
#include "Animation.h"


// Animation

IMPLEMENT_DYNAMIC(Animation, CWnd)

Animation::Animation()
{

	// 초기화

	int fir = 312;

	for (int i = 0; i < 5; i++)
	{

		CBitmap bitmap;
		BITMAP bmpinfo;

		bitmaps[i].LoadBitmap(fir + i);
		bitmaps[i].GetBitmap(&bmpinfo);

	}






}

Animation::~Animation()
{
}


BEGIN_MESSAGE_MAP(Animation, CWnd)
END_MESSAGE_MAP()



// Animation 메시지 처리기


