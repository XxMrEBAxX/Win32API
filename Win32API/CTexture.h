#pragma once
class CTexture
{
private:
	HDC m_hDC; // 리소스에 대한 DC
	HBITMAP m_hBit; // 리소스에 대한 비트맵

public:
	void Load(const wstring& _strFilePath);

	CTexture();
	~CTexture();
};

