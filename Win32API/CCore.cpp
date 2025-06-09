#include "pch.h"
#include "CCore.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"

CObject g_obj;

int CCore::Init(HWND hWnd, POINT ptResolution)
{
	m_hWnd = hWnd;
	m_ptResolution = ptResolution;

	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// Manager ÃÊ±âÈ­
	CTimeMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();

	g_obj.SetPos(Vec2{ static_cast<int>(m_ptResolution.x / 2), static_cast<int>(m_ptResolution.y / 2) });
	g_obj.SetScale(Vec2{ 100, 100 });

	return S_OK;
}

void CCore::progress()
{
	CTimeMgr::GetInst()->update();

	update();

	render();
}

void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200.f * fDT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * fDT;
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC, 
		  static_cast<int>(vPos.x - vScale.x / 2)
		, static_cast<int>(vPos.y - vScale.y / 2)
		, static_cast<int>(vPos.x + vScale.x / 2)
		, static_cast<int>(vPos.y + vScale.y / 2)
	);
}

CCore::CCore() : m_hWnd(0), m_ptResolution{}, m_hDC(0)
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}