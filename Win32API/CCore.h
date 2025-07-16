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
	HWND		m_hWnd;			// ���� ������ �ڵ�
	POINT		m_ptResolution; // ���� ������ �ػ�
	HDC			m_hDC; // ���� �������� Draw�� DC

	HBITMAP m_hBit;
	HDC		m_memDC;

	void update();
	void render();
};

