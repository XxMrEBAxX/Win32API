#include "pch.h"
#include "CTimeMgr.h"
#include "CCore.h"
#include <tchar.h>

CTimeMgr::CTimeMgr()
	: m_llCurCount{},
	  m_llPrevCount{},
	  m_llFrequency{},
	  m_dDT(0.0),
	  m_iCallCount(0),
	  m_dAcc(0.0),
	  m_iFPS(0)
{
	
}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::Init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);

	// 초당 카운트
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	m_llPrevCount = m_llCurCount;
}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.0)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.0;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d,  DT : %f", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
