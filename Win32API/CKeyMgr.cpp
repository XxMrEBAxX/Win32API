#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"

int g_arrVK[static_cast<int>(KEY::LAST)] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',

	VK_MENU, // ALT
	VK_CONTROL, // LCTRL
	VK_LSHIFT, // LSHIFT
	VK_SPACE, //SPACE
	VK_RETURN, //ENTER
	VK_ESCAPE
};

CKeyMgr::CKeyMgr()
{
}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
	for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}

	
}

void CKeyMgr::update()
{
	// 윈도우 포커싱 알아내기
	//HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
	HWND hWnd = GetFocus();

	if (nullptr != hWnd)
	{
		for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
				{
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}

			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
		{
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
	
}
