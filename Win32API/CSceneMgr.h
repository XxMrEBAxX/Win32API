#pragma once

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene*		m_arrScene[static_cast<UINT>(SCENE_TYPE::END)];
	CScene*		m_pCurScene;

public:
	void init();

	CSceneMgr();
	~CSceneMgr();
};

