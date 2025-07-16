#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"

void CMonster::update()
{
	Vec2 vCurPos = GetPos();

	vCurPos.x += fDT * m_fSpeed * m_iDir;

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	if (fDist > 0)
	{
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}

CMonster::CMonster() : m_fSpeed(100.f)
					, m_vCenterPos(Vec2(0.f, 0.f))
					, m_fMaxDistance(50.f)
					, m_iDir(1)
{

}

CMonster::~CMonster()
{

}
