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
		delete m_arrScene[i]; // c++14 부터 알아서 nullptr 거름
	}
}

void CSceneMgr::init()
{
	m_arrScene[static_cast<UINT>(SCENE_TYPE::START)] = new CScene_Start;

	m_pCurScene = m_arrScene[static_cast<UINT>(SCENE_TYPE::START)];
}