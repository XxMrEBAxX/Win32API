#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr)

private:
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;

	double			m_dAcc;
	double			m_dDT; // Delta Time
	UINT			m_iCallCount; // 호출 횟수
	UINT			m_iFPS; // 초당 프레임 수

public:
	void Init();
	void update();
	void render();

	double GetDT() const { return m_dDT; };
	float GetfDT() const { return static_cast<float>(m_dDT); }
};