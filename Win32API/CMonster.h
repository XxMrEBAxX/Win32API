#pragma once

#include "CObject.h"

class CMonster : public CObject
{
private:
	float		m_fSpeed;

	Vec2		m_vCenterPos;
	float		m_fMaxDistance;
	int			m_iDir;

public:
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _f) { m_fSpeed = _f; }

	void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
	void SetMaxDistance(float _f) { m_fMaxDistance = _f; }

	virtual void update();

	CMonster();
	~CMonster();
};

