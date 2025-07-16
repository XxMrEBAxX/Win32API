#pragma once
#include "pch.h"
#include "CObject.h"

class CCore
{
	SINGLE(CCore)

public:
	int Init(HWND hWnd, POINT ptResolution);
	void progress();
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }

private:
	HWND		m_hWnd;			// 메인 윈도우 핸들
	POINT		m_ptResolution; // 메인 윈도우 해상도
	HDC			m_hDC; // 메인 윈도우의 Draw할 DC

	HBITMAP m_hBit;
	HDC		m_memDC;

	void update();
	void render();
};

