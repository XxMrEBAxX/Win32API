#pragma once

#include "CObject.h"

class CPlayer : public CObject
{
public:
	virtual void update() override;
	void CreateMissile();
};

