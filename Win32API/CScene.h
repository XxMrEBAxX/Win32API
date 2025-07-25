#pragma once

// ���� ����
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[static_cast<UINT>(GROUP_TYPE::END)];
	wstring			 m_strName;

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[static_cast<UINT>(_eType)].push_back(_pObj);
	}

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void render(HDC _dc);
	
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	CScene();
	virtual ~CScene();
};

