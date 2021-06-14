
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once

#include "Player.h"
#include "Bullet.h"
#include "CInput.h"
#include "Monster.h"
#include "MapManager.h"
#include "ColliderManager.h"

#define MONSTER_SIZE 64

// CChildView 창

class CChildView : public CWnd
{
	// 생성입니다.
public:
	CChildView();

	// 특성입니다.
public:

	Player player;
	CInput inputManager;

	// 사용할 오브젝트 50개

	MapManager mapManager;
	Animation booms[10];

	






	// 작업입니다.
public:
	void ColliderCheck();
	void BoomAnim(int x, int y);


	// 재정의입니다.
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

