#pragma once

// 전방 선언
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[static_cast<UINT>(GROUP_TYPE::END)];
	wstring			 m_strName;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	CScene();
	virtual ~CScene();
};

