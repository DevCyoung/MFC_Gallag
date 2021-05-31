
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"

#include "Gallag.h"

#include "ChildView.h"
#include "Player.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif





CChildView::CChildView()
{

	CRect rect;
	rect.right = GetSystemMetrics(SM_CXSCREEN);
	rect.bottom = GetSystemMetrics(SM_CYSCREEN);

	player.SetPosition(rect.right / 2, rect.bottom - player.bmpinfo.bmHeight - 50);

}

CChildView::~CChildView()
{
}



BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	//	ON_WM_CREATE()
	//ON_WM_TIMER()
	//ON_WM_CREATE()
//	ON_WM_KEYDOWN()
//	ON_WM_KEYUP()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()



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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	SetTimer(10, 20, NULL);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.


	player.Show(dc);


	//우선 총알 전체 보여줌....

	for (int i = 0; i < BULLET_SIZE; i++)
	{

		if (player.bullets[i].isShoot)
		{
			player.bullets[i].Show(dc);
			player.bullets[i].DirMoveTick();
		}

	}

}




void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate();

	inputManager.Controller(player, 1);

	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();
	KillTimer(1);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


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
