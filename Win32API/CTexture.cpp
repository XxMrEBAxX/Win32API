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

	// ��Ʈ�ʰ� ������ DC
	m_hDC = CreateCompatibleDC(CCore::GetInst()->GetInst()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBit);

	// ���� ���� ����
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}