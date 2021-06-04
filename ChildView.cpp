
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Gallag.h"
#include "ChildView.h"
#include "Player.h"
#include "Monster.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CChildView::CChildView()
{

	

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_KEYDOWN()
ON_WM_KEYUP()
ON_WM_CREATE()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	SetTimer(10, 20, NULL);

	return 0;
}

// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{

	// 그리기를 위한 디바이스 컨텍스트입니다.
	CPaintDC dc(this); 

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	player.Show(dc);

	//Paint Monster
	for (int i = 0; i < 50; i++)
	{
		monsters[i].DirMoveTick();
		monsters[i].Show(dc);
	}
		
	//Paint Monster && bullet Tick Move
	for (int i = 0; i < BULLET_SIZE; i++)
	{
		player.bullets[i].DirMoveTick();
		player.bullets[i].Show(dc);

	}

	//Collide Check
	for (int i = 0; i < BULLET_SIZE; i++)
	{

		if (player.bullets[i].isAlive == false) 
			continue;
	
		for (int j = 0; j < 50; j++)
		{

			if (monsters[j].isAlive == false)
				continue;
		
			if ( player.bullets[i].IsCollide(monsters[j]) )
			{

				player.bullets[i].isAlive = false;
				monsters[j].isAlive = false;

			}
		}
	}
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	// Controller
	inputManager.Controller(player, 1);
	Invalidate();

	CWnd::OnTimer(nIDEvent);
}

// 방향키 , 스페이스바 
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	switch (nChar)
	{

	case VK_LEFT:
		inputManager.STATE |= inputManager.LEFT;
		break;
	case VK_RIGHT:
		inputManager.STATE |= inputManager.RIGHT;
		break;
	case VK_SPACE:
		inputManager.STATE |= inputManager.SPACE;
		break;

	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

// 방향키 , 스페이스바 
void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	switch (nChar)
	{

	case VK_LEFT:

		if (inputManager.STATE & inputManager.LEFT)
			inputManager.STATE ^= inputManager.LEFT;
		break;

	case VK_RIGHT:

		if (inputManager.STATE & inputManager.RIGHT)
			inputManager.STATE ^= inputManager.RIGHT;
		break;

	case VK_SPACE:

		if (inputManager.STATE & inputManager.SPACE)
			inputManager.STATE ^= inputManager.SPACE;
		break;

	}

	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

// 임시 백그라운드

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{

	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return TRUE;
	//return CWnd::OnEraseBkgnd(pDC);
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);

}


