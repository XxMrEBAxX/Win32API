#pragma once
class CRes
{
private:
	wstring m_strKey;	// ���ҽ� Ű
	wstring m_strRelativePath; // ���ҽ� ��� ���

public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strRelativePath) { m_strRelativePath = _strRelativePath; }

	const wstring& GetKey() const { return m_strKey; }
	const wstring& GetRelativePath() const { return m_strRelativePath; }

	CRes();
	virtual ~CRes();
};

