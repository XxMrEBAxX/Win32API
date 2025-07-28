#include "pch.h"
#include "CTexture.h"
#include "CCore.h"


CTexture::CTexture()
	: m_hBit(0)
	, m_hDC(0)
	, m_bitInfo({ })
{

}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

void CTexture::Load(const wstring& _strFilePath)
{
	m_hBit = static_cast<HBITMAP>(LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));
	assert(m_hBit);

	// 비트맵과 연결할 DC
	m_hDC = CreateCompatibleDC(CCore::GetInst()->GetInst()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBit);

	// 가로 세로 길이
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}