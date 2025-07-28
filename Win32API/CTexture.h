#pragma once
class CTexture
{
private:
	HDC m_hDC; // ���ҽ��� ���� DC
	HBITMAP m_hBit; // ���ҽ��� ���� ��Ʈ��
	BITMAP m_bitInfo; // ��Ʈ�� ����

public:
	void Load(const wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }
	HDC GetDC() { return m_hDC; }

	CTexture();
	~CTexture();
};

