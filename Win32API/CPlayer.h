#pragma once

#include "CObject.h"
#include "CTexture.h"

class CPlayer : public CObject
{
private:
	CTexture* m_pTex;

public:
	virtual void update() override;
	virtual void render(HDC _dc) override;

	void CreateMissile();

	CPlayer();
	~CPlayer();
};

