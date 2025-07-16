#include "pch.h"
#include "CSceneMgr.h"

#include "CScene_Start.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	for (UINT i = 0; i < static_cast<UINT>(SCENE_TYPE::END); i++)
	{
		delete m_arrScene[i]; // c++14 ���� �˾Ƽ� nullptr �Ÿ�
	}
}

void CSceneMgr::init()
{
	m_arrScene[static_cast<UINT>(SCENE_TYPE::START)] = new CScene_Start;
	m_arrScene[static_cast<UINT>(SCENE_TYPE::START)]->SetName(L"Start Scene");

	m_pCurScene = m_arrScene[static_cast<UINT>(SCENE_TYPE::START)];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}
