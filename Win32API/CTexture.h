#pragma once
class CTexture
{
private:
	HDC m_hDC; // 리소스에 대한 DC
	HBITMAP m_hBit; // 리소스에 대한 비트맵
	BITMAP m_bitInfo; // 비트맵 정보

public:
	void Load(const wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }
	HDC GetDC() { return m_hDC; }

	CTexture();
	~CTexture();
};

