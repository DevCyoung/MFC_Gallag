
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

	/// ///////////////////////////////////////////////////////////////////
	/// Double buffering

	CRect clientRect;
	GetClientRect(&clientRect);

	CDC memDC;
	CBitmap memBitmap;
	memDC.CreateCompatibleDC(&dc);
	memBitmap.CreateCompatibleBitmap(&dc, clientRect.right, clientRect.bottom);
	CBitmap* pOldBitmap = (CBitmap*)memDC.SelectObject(&memBitmap);

	/// Double buffering
	/// ///////////////////////////////////////////////////////////////////


	player.Show(memDC);

	//Show Monster

	for (int i = 0; i < MONSTER_PULL; i++)
	{
		mapManager.monsters[i].DirMoveTick();
		mapManager.monsters[i].Show(memDC);
	}

	//Bullet Tick Move , Show

	for (int i = 0; i < BULLET_PULL; i++)
	{
		player.bullets[i].DirMoveTick();
		player.bullets[i].Show(memDC);
	}

	//BoomShow

	for (int i = 0; i < BOOM_ANIM_PULL; i++)
	{

		if (booms[i].isShow == true)
			booms[i].Show(memDC);

	}

	/// ///////////////////////////////////////////////////////////////////
	/// Double buffering

	dc.BitBlt(0, 0, clientRect.right, clientRect.bottom, &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	ReleaseDC(&memDC);

	/// Double buffering
	/// ///////////////////////////////////////////////////////////////////

}
int Level = 30;
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	// Controller
	inputManager.Controller(player, 1);

	//Collide Check
	ColliderCheck();

	// 생성 패턴 

	if (mapManager.DieMonster > 30)
	{
		mapManager.DieMonster -= 31;
		mapManager.CreateMonster(31);
	}

	if (mapManager.CountDieMonster >= Level )
	{
		Level *= 3;
		mapManager.CountDieMonster = 0;
		if( player.curPower < 5 )
			player.curPower++;

	}
	

	Invalidate(FALSE);

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
	case VK_ESCAPE:
		AfxGetApp()->m_pMainWnd->PostMessage(WM_CLOSE);

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
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{

	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return FALSE;

	//return CWnd::OnEraseBkgnd(pDC);
}
void CChildView::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);

}
void CChildView::ColliderCheck()
{
	for (int i = 0; i < BULLET_PULL; i++)
	{

		if (player.bullets[i].isAlive == false)
			continue;

		for (int j = 0; j < MONSTER_PULL; j++)
		{


			if (mapManager.monsters[j].isAlive == false)
				continue;


			if (player.bullets[i].IsCollide(mapManager.monsters[j]))
			{

				// 총알과 몬스터 충돌시 일어나는일
				Monster* monster = &mapManager.monsters[j];

				monster->isAlive = false;
				player.bullets[i].isAlive = false;
				mapManager.tiles[monster->i][monster->j].isAlive = false;

				//Boom anim On
				
				BoomAnim(monster->x, monster->y);

				++mapManager.DieMonster;
				++mapManager.CountDieMonster;
				break;
			}
		}
	}
}
void CChildView::BoomAnim(int x,  int y)
{

	booms[pos].isShow = true;
	booms[pos].x = x;
	booms[pos].y = y;
	pos++;

	if (pos >= 10)
		pos = 0;


}

