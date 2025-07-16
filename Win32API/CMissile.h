#pragma once
#include "CObject.h"

class CMissile : public CObject
{
private:
	float		m_fDir;

public:
	CMissile();
	~CMissile();

	virtual void update();
	virtual void render(HDC _dc);

	void SetDir(bool _bUp)
	{
		if (_bUp)
			m_fDir = -1.f;
		else
			m_fDir = 1.f;
	}
};

