#pragma once
#include "pch.h"

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST
};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrevPush;
};

class CKeyMgr
{
	SINGLE(CKeyMgr)
private:
	vector<tKeyInfo> m_vecKey;
public:
	void init();
	void update();

	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[static_cast<int>(_eKey)].eState;
	}
};

