#pragma once
class CTexture
{
private:
	HDC m_hDC; // ���ҽ��� ���� DC
	HBITMAP m_hBit; // ���ҽ��� ���� ��Ʈ��

public:
	CTexture();
	~CTexture();
};

